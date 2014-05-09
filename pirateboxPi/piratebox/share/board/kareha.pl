#!/usr/bin/perl

use CGI::Carp qw(fatalsToBrowser);

use strict;

use CGI;
use Data::Dumper;
use Fcntl ':flock';

use lib '.';
BEGIN { require 'config.pl'; }
BEGIN { require 'config_defaults.pl'; }
BEGIN { require 'templates.pl'; }
BEGIN { require 'captcha.pl'; }
BEGIN { require 'wakautils.pl'; }

return 1 if(caller);



#
# Global init
#

no strict; # disable strictness to create global variables visible to the templates
$stylesheets=get_stylesheets();
$markup_formats=[map +{id=>$_},MARKUP_FORMATS];
use strict;

my $replyrange_re=qr{n?(?:[0-9\-,lrq]|&#44;)*[0-9\-lrq]}; # regexp to match reply ranges for >> links
my $protocol_re=protocol_regexp();
my $url_re=url_regexp();

my $query=new CGI;
my $task=$query->param("task");

# Rebuild main page if it doesn't exist
unless(-e HTML_SELF)
{
	build_pages();
	update_threads();
}

if(!$task)
{
	if($ENV{PATH_INFO}) { show_thread($ENV{PATH_INFO}) }
	else { make_http_forward(HTML_SELF,ALTERNATE_REDIRECT) }
	exit 0;
}

my $log=lock_log();

if($task eq "post")
{
	my $thread=$query->param("thread");
	my $name=$query->param("field_a");
	my $link=$query->param("field_b");
	my $title=$query->param("title");
	my $comment=$query->param("comment");
	my $captcha=$query->param("captcha");
	my $password=$query->param("password");
	my $file=$query->param("file");
	my $markup=$query->param("markup");
	my $savemarkup=$query->param("savemarkup");
	my $key=$query->cookie("captchakey");

	post_stuff($thread,$name,$link,$title,$comment,$captcha,$key,$password,$markup,$savemarkup,$file,$file);
}
elsif($task eq "preview")
{
	my $comment=$query->param("comment");
	my $markup=$query->param("markup");
	my $thread=$query->param("thread");

	preview_post($comment,$markup,$thread);
	exit;
}
elsif($task eq "delete")
{
	my $password=$query->param("password");
	my $fileonly=$query->param("fileonly");
	my @posts=$query->param("delete");

	delete_stuff($password,$fileonly,@posts);
}
elsif($task eq "deletethread")
{
	make_error(S_BADDELPASS) unless check_admin_pass($query->param("admin"));

	my $thread=$query->param("thread");
	delete_thread($thread);
}
elsif($task eq "permasagethread")
{
	make_error(S_BADDELPASS) unless check_admin_pass($query->param("admin"));

	my $thread=$query->param("thread");
	my $state=$query->param("state");
	permasage_thread($thread,$state);
}
elsif($task eq "closethread")
{
	make_error(S_BADDELPASS) unless check_admin_pass($query->param("admin"));

	my $thread=$query->param("thread");
	my $state=$query->param("state");
	close_thread($thread,$state);
}
elsif($task eq "rebuild")
{
	make_error(S_BADDELPASS) unless check_admin_pass($query->param("admin"));

	build_pages();
	update_threads();
}
else
{
	make_error(S_NOTASK);
}

release_log($log);

if($query->param("r")) { make_http_forward($ENV{HTTP_REFERER},ALTERNATE_REDIRECT) }
else { make_http_forward(HTML_SELF,ALTERNATE_REDIRECT) }

#
# End of main code
#


sub show_thread($)
{
	my ($path)=@_;
	my ($threadnum,$ranges)=$path=~m!/([0-9]+)(?:/(.*)|)!i;
	my $modified=(stat RES_DIR.$threadnum.PAGE_EXT)[9];

	if($ENV{HTTP_IF_MODIFIED_SINCE})
	{
		my $ifmod=parse_http_date($ENV{HTTP_IF_MODIFIED_SINCE});
		if($modified<=$ifmod)
		{
			print "Status: 304 Not modified\n\n";
			return;
		}
	}

	my $thread=filter_post_ranges($threadnum,$ranges);

	print "Content-Type: ".get_xhtml_content_type(CHARSET,USE_XHTML)."\n";
	print "Date: ".make_date(time(),"http")."\n";
	print "Last-Modified: ".make_date($modified,"http")."\n";
	print "\n";

	my %thread=%{$thread};

	print join "\n",(
		THREAD_HEAD_TEMPLATE->(%{$thread}),
		(map { $$_{text} } @{$$thread{posts}}),
		THREAD_FOOT_TEMPLATE->(%{$thread}),
	);
}

sub build_pages()
{
	my @allthreads=get_threads(1);
	my @copy=@allthreads;
	my @pages;

	# generate page subdivisions
	if(PAGE_GENERATION eq "paged")
	{
		$pages[0]{threads}=[splice @copy,0,THREADS_DISPLAYED];
		$pages[0]{filename}=HTML_SELF;
		$pages[0]{page}="0";

		my @threads;
		while(@threads=splice @copy,0,THREADS_DISPLAYED)
		{
			push @pages,{ threads=>[@threads],filename=>@pages.PAGE_EXT,page=>scalar @pages };
		}
	}
	elsif(PAGE_GENERATION eq "monthly")
	{
		$pages[0]{threads}=[splice @copy,0,THREADS_DISPLAYED];
		$pages[0]{filename}=HTML_SELF;
		$pages[0]{page}=S_FRONT;

		my @unbumped=sort { $$b{thread}<=>$$a{thread} } @allthreads;
		foreach my $thread (@unbumped) { $$thread{month}=make_date($$thread{thread},"month") }

		while(@unbumped)
		{
			my @month=(shift @unbumped);
			while(@unbumped and $unbumped[0]{month} eq $month[0]{month}) { push @month,shift @unbumped }

			my $monthname=$month[0]{month};
			my $filename=lc($monthname).PAGE_EXT;
			$filename=~tr/ /_/;

			push @pages,{ threads=>\@month,filename=>$filename,page=>$monthname };
		}
	}
	else
	{
		$pages[0]{threads}=[splice @copy,0,THREADS_DISPLAYED];
		$pages[0]{filename}=HTML_SELF;
		$pages[0]{page}=S_FRONT;
	}

	# figure out next/prev links
	for(1..$#pages-1)
	{
		$pages[$_]{nextpage}=$pages[$_+1]{filename};
		$pages[$_]{prevpage}=$pages[$_-1]{filename};
	}
	if(@pages>1)
	{
		$pages[0]{nextpage}=$pages[1]{filename};
		$pages[$#pages]{prevpage}=$pages[$#pages-1]{filename};
	}

	# process and generate pages
	foreach my $page (@pages)
	{
		# fix up each thread
		foreach my $thread (@{$$page{threads}})
		{
			read_thread($thread);

			my $posts=$$thread{postcount};
			my $images=grep { get_post_images($thread,$_) } 1..$posts;
			my $curr_replies=$posts-1;
			my $curr_images=$images;
			my $max_replies=REPLIES_PER_THREAD;
			my $max_images=(IMAGE_REPLIES_PER_THREAD or $images);
			my $start=2;

			# drop replies until we have few enough replies and images
			while($curr_replies>$max_replies or $curr_images>$max_images)
			{
				$curr_images-- if(get_post_images($thread,$start));
				$curr_replies--;
				$start++;
			}

			filter_post_ranges($thread,"l$curr_replies",MAX_LINES_SHOWN);

			$$thread{omit}=$posts-$curr_replies-1;
			$$thread{omitimages}=$images-$curr_images;

			$$thread{nextnum}=$$thread{num}%(THREADS_DISPLAYED)+1;
			$$thread{prevnum}=($$thread{num}+(THREADS_DISPLAYED)-2)%(THREADS_DISPLAYED)+1;
		}

		write_array($$page{filename},MAIN_PAGE_TEMPLATE->(
			%$page,
			pages=>\@pages,
			allthreads=>\@allthreads,
			current=>$$page{page},
		));
	}

	write_array(HTML_BACKLOG,BACKLOG_PAGE_TEMPLATE->(threads=>\@allthreads)) if(HTML_BACKLOG);
	write_array(RSS_FILE,RSS_TEMPLATE->(threads=>\@allthreads)) if(RSS_FILE);

	# delete extra pages
	# BUG: no deletion in monthly mode
	if(PAGE_GENERATION eq "paged")
	{
		my $page=@pages;
		while(-e $page.PAGE_EXT)
		{
			unlink $page.PAGE_EXT;
			$page++;
		}
	}
}

sub update_threads()
{
	my @threads=get_threads(1);

	foreach my $thread (@threads)
	{
		read_thread($thread);
		write_thread($thread);
	}
}



#
# Posting
#

sub post_stuff($$$$$$$$$$$$)
{
	my ($thread,$name,$link,$title,$comment,$captcha,$key,$password,$markup,$savemarkup,$file,$uploadname)=@_;

	# get a timestamp for future use
	my $time=time();

	# check that the request came in as a POST, or from the command line
	make_error(S_UNJUST) if $ENV{REQUEST_METHOD} and $ENV{REQUEST_METHOD} ne "POST";

	# check for weird characters
	make_error(S_UNUSUAL) if $thread=~/[^0-9]/;
	make_error(S_UNUSUAL) if length($thread)>10;
	make_error(S_UNUSUAL) if $name=~/[\n\r]/;
	make_error(S_UNUSUAL) if $link=~/[\n\r]/;
	make_error(S_UNUSUAL) if $title=~/[\n\r]/;

	# check for excessive amounts of text
	make_error(sprintf(S_TOOLONG,"name",length($name)-&MAX_FIELD_LENGTH)) if length($name)>MAX_FIELD_LENGTH;
	make_error(sprintf(S_TOOLONG,"link",length($link)-&MAX_FIELD_LENGTH)) if length($link)>MAX_FIELD_LENGTH;
	make_error(sprintf(S_TOOLONG,"title",length($title)-&MAX_FIELD_LENGTH)) if length($title)>MAX_FIELD_LENGTH;
	make_error(sprintf(S_TOOLONG,"comment",length($comment)-&MAX_COMMENT_LENGTH)) if length($comment)>MAX_COMMENT_LENGTH;

	# check for empty post
	make_error(S_NOTEXT) if $comment=~/^\s*$/ and !$file;
	make_error(S_NOTITLE) if REQUIRE_THREAD_TITLE and $title=~/^\s*$/ and !$thread;

	# find hostname
	my $ip=$ENV{REMOTE_ADDR};
	#$host = gethostbyaddr($ip);

	# spam check
	spam_engine(
		query=>$query,
		trap_fields=>SPAM_TRAP?["name","link"]:[],
		spam_files=>[SPAM_FILES],
		charset=>CHARSET,
	);

	# check captcha
	if(ENABLE_CAPTCHA)
	{
		make_error(S_BADCAPTCHA) if find_key($log,$key);
		make_error(S_BADCAPTCHA) if !check_captcha($key,$captcha);
	}

	# proxy check - not implemented yet, and might not ever be
	#proxy_check($ip) unless($whitelisted);

	# remember cookies
	my $c_name=$name;
	my $c_link=$link;
	my $c_password=$password;
	my $c_markup=$markup;

	# kill the name if anonymous posting is being enforced
	if(FORCED_ANON)
	{
		$name='';
		if($link=~/sage/i) { $link='sage' }
		else { $link='' }
	}

	# clean up the inputs
	$link=clean_string($link);
	$title=clean_string($title);

	# fix up the link
	$link="mailto:$link" if $link and $link!~/^$protocol_re/;

	# process the tripcode
	my ($trip,$capped);
	($name,$trip)=process_tripcode($name,TRIPKEY,SECRET,CHARSET,1);
	my %capped_trips=CAPPED_TRIPS;
	$capped=$capped_trips{$trip};

	# insert anonymous name if none entered
	$name=make_anonymous($ip,$time,($thread or $time)) unless $name or $trip;

	# reveal host when name is "fusianasan"
	($name,$trip)=("",resolve_host($ENV{REMOTE_ADDR}).$trip) if $name=~/fusianasan/i;

	# check for posting limitations
	unless($capped)
	{
		if($thread)
		{
			make_error(S_NOTALLOWED) if($file and !ALLOW_IMAGE_REPLIES);
			make_error(S_NOTALLOWED) if(!$file and !ALLOW_TEXT_REPLIES);
		}
		else
		{
			make_error(S_NOTALLOWED) if($file and !ALLOW_IMAGE_THREADS);
			make_error(S_NOTALLOWED) if(!$file and !ALLOW_TEXT_THREADS);
		}
	}

	# copy file, do checksums, make thumbnail, etc
	my ($filename,$ext,$size,$md5,$width,$height,$thumbnail,$tn_width,$tn_height)=process_file($file,$uploadname,$time) if($file);

	# create the thread if we are starting a new one
	$thread=make_thread($title,$time,$name.$trip) unless $thread;

	# format the comment
	$comment=format_comment($comment,$markup,$thread);

	# generate date
	my $date=make_date($time,DATE_STYLE);

	# generate ID code if enabled
	$date.=' ID:'.make_id_code($ip,$time,$link,$thread) if DISPLAY_ID;

	# add the reply to the thread
	my $num=make_reply(
		ip=>$ip,thread=>$thread,name=>$name,trip=>$trip,link=>$link,capped=>$capped,
		time=>$time,date=>$date,title=>$title,comment=>$comment,
		image=>$filename,ext=>$ext,size=>$size,md5=>$md5,width=>$width,height=>$height,
		thumbnail=>$thumbnail,tn_width=>$tn_width,tn_height=>$tn_height,
	);

	# make entry in the log
	add_log($log,$thread,$num,$password,$ip,$key,$md5,$filename);

	# remove old threads from the database
	trim_threads();

	build_pages();

	# set the name, email and password cookies, plus a new captcha key
	make_cookies(name=>$c_name,link=>$c_link,password=>$c_password,
	$savemarkup?(markup=>$c_markup):(),
	captchakey=>make_random_string(8),-charset=>CHARSET,-autopath=>COOKIE_PATH); # yum!
}

sub preview_post($$$)
{
	my ($comment,$markup,$thread)=@_;

	$thread=time() unless $thread;

	make_error(S_UNUSUAL) unless grep $markup eq $_,MARKUP_FORMATS;
	make_error(sprintf(S_TOOLONG,"comment",length($comment)-&MAX_COMMENT_LENGTH)) if length($comment)>MAX_COMMENT_LENGTH;

	# format the comment
	$comment=format_comment($comment,$markup,$thread);

	print "Content-Type: text/html\n";
	print "\n";
	print $comment;
}

sub proxy_check($)
{
	my ($ip)=@_;

	for my $port (PROXY_CHECK)
	{
		# needs to be implemented
		# die sprintf S_PROXY,$port);
	}
}

sub format_comment($$$)
{
	my ($comment,$markup,$thread)=@_;

	$markup=DEFAULT_MARKUP unless grep $markup eq $_,MARKUP_FORMATS;

	if($markup eq "none") { $comment=simple_format($comment,$thread) }
	elsif($markup eq "html") { $comment=html_format($comment,$thread) }
	elsif($markup eq "raw") { $comment=raw_html_format($comment,$thread) }
	elsif($markup eq "aa") { $comment=aa_format($comment,$thread) }
	else { $comment=wakabamark_format($comment,$thread) }

	# fix <blockquote> styles for old stylesheets
	$comment=~s/<blockquote>/<blockquote class="unkfunc">/g if(FUDGE_BLOCKQUOTES);

	return $comment;
}

sub simple_format($$)
{
	my ($text,$thread)=@_;

	return join "<br />",map
	{
		my $line=$_;

		$line=~s!&gt;&gt;($replyrange_re)!\<a href="$ENV{SCRIPT_NAME}/$thread/$1" rel="nofollow"\>&gt;&gt;$1\</a\>!gm;

		# make URLs into links
		$line=~s{$url_re}{\<a href="$1" rel="nofollow"\>$1\</a\>$2}sgi;

		$line;
	} split /(?:\r\n|\n|\r)/,clean_string(decode_string($text));
}

sub aa_format($$)
{
	my ($text,$thread)=@_;

	return '<div class="aa">'.simple_format($text,$thread).'</div>';
}

sub wakabamark_format($$)
{
	my ($text,$thread)=@_;

	$text=clean_string(decode_string($text));

	# hide >>1 references from the quoting code
	$text=~s/&gt;&gt;($replyrange_re)/&gtgt;$1/g;

	my $handler=sub # fix up >>1 references
	{
		my $line=shift;
		$line=~s!&gtgt;($replyrange_re)!\<a href="$ENV{SCRIPT_NAME}/$thread/$1" rel="nofollow"\>&gt;&gt;$1\</a\>!gm;
		return $line;
	};

	$text=do_wakabamark($text,$handler);

	# restore >>1 references hidden in code blocks
	$text=~s/&gtgt;/&gt;&gt;/g;

	return $text;
}

sub html_format($$)
{
	my ($text,$thread)=@_;

	$text=sanitize_html(decode_string($text),ALLOWED_HTML);

	$text=~s!&gt;&gt;($replyrange_re)!\<a href="$ENV{SCRIPT_NAME}/$thread/$1" rel="nofollow"\>&gt;&gt;$1\</a\>!gm;
	$text=~s!(?:\r\n|\n|\r)!<br />!sg;

	return $text;
}

sub raw_html_format($4)
{
	my ($text,$thread)=@_;

	$text=sanitize_html($text,ALLOWED_HTML);
	$text=~s!\s+! !sg;

	return $text;
}


sub make_anonymous($$$)
{
	my ($ip,$time,$thread)=@_;

	return S_ANONAME unless(SILLY_ANONYMOUS);

	my $string=$ip;
	$string.=",".int($time/86400) if(SILLY_ANONYMOUS=~/day/i);
	$string.=",".$ENV{SCRIPT_NAME} if(SILLY_ANONYMOUS=~/board/i);
	$string.=",".$thread if(SILLY_ANONYMOUS=~/thread/i);

	srand unpack "N",hide_data($string,4,"silly",SECRET);

	return cfg_expand("%G% %W%",
		W => ["%B%%V%%M%%I%%V%%F%","%B%%V%%M%%E%","%O%%E%","%B%%V%%M%%I%%V%%F%","%B%%V%%M%%E%","%O%%E%","%B%%V%%M%%I%%V%%F%","%B%%V%%M%%E%"],
		B => ["B","B","C","D","D","F","F","G","G","H","H","M","N","P","P","S","S","W","Ch","Br","Cr","Dr","Bl","Cl","S"],
		I => ["b","d","f","h","k","l","m","n","p","s","t","w","ch","st"],
		V => ["a","e","i","o","u"],
		M => ["ving","zzle","ndle","ddle","ller","rring","tting","nning","ssle","mmer","bber","bble","nger","nner","sh","ffing","nder","pper","mmle","lly","bling","nkin","dge","ckle","ggle","mble","ckle","rry"],
		F => ["t","ck","tch","d","g","n","t","t","ck","tch","dge","re","rk","dge","re","ne","dging"],
		O => ["Small","Snod","Bard","Billing","Black","Shake","Tilling","Good","Worthing","Blythe","Green","Duck","Pitt","Grand","Brook","Blather","Bun","Buzz","Clay","Fan","Dart","Grim","Honey","Light","Murd","Nickle","Pick","Pock","Trot","Toot","Turvey"],
		E => ["shaw","man","stone","son","ham","gold","banks","foot","worth","way","hall","dock","ford","well","bury","stock","field","lock","dale","water","hood","ridge","ville","spear","forth","will"],
		G => ["Albert","Alice","Angus","Archie","Augustus","Barnaby","Basil","Beatrice","Betsy","Caroline","Cedric","Charles","Charlotte","Clara","Cornelius","Cyril","David","Doris","Ebenezer","Edward","Edwin","Eliza","Emma","Ernest","Esther","Eugene","Fanny","Frederick","George","Graham","Hamilton","Hannah","Hedda","Henry","Hugh","Ian","Isabella","Jack","James","Jarvis","Jenny","John","Lillian","Lydia","Martha","Martin","Matilda","Molly","Nathaniel","Nell","Nicholas","Nigel","Oliver","Phineas","Phoebe","Phyllis","Polly","Priscilla","Rebecca","Reuben","Samuel","Sidney","Simon","Sophie","Thomas","Walter","Wesley","William"],
	);
}

sub make_id_code($$$$)
{
	my ($ip,$time,$link,$thread)=@_;

	return EMAIL_ID if($link and DISPLAY_ID=~/link/i);
	return EMAIL_ID if($link=~/sage/i and DISPLAY_ID=~/sage/i);

	return resolve_host($ENV{REMOTE_ADDR}) if(DISPLAY_ID=~/host/i);
	return $ENV{REMOTE_ADDR} if(DISPLAY_ID=~/ip/i);

	my $string="";
	$string.=",".int($time/86400) if(DISPLAY_ID=~/day/i);
	$string.=",".$ENV{SCRIPT_NAME} if(DISPLAY_ID=~/board/i);
	$string.=",".$thread if(DISPLAY_ID=~/thread/i);

	return mask_ip($ENV{REMOTE_ADDR},make_key("mask",SECRET,32).$string) if(DISPLAY_ID=~/mask/i);

	return hide_data($ip.$string,6,"id",SECRET,1);
}

sub make_reply(%)
{
	my (%vars)=@_;

	my $thread=read_thread($vars{thread});

	make_error(S_THREADCLOSED) if($$thread{closed});

	$$thread{postcount}++;
	$$thread{lastmod}=$vars{time};
	$$thread{lasthit}=$vars{time} unless($vars{link}=~/sage/i or $$thread{postcount}>=MAX_RES or $$thread{permasage}); # bump unless sage, too many replies, or permasage

	my $num=$$thread{postcount};
	set_post_text($thread,$num,REPLY_TEMPLATE->(%vars,num=>$num));

	write_thread($thread);

	return $num;
}



#
# Deleting
#

sub delete_stuff($@)
{
	my ($password,$fileonly,@posts)=@_;

	foreach my $post (@posts)
	{
		my ($thread,$num)=$post=~/([0-9]+),([0-9]+)/;

		delete_post($thread,$num,$password,$fileonly);
	}

	build_pages();
}

sub trim_threads()
{
	my @threads=get_threads(TRIM_METHOD);

	my ($posts,$size);
	$posts+=$$_{postcount} for(@threads);
	$size+=-s $_ for(glob(IMG_DIR."*"));

	my $max_threads=(MAX_THREADS or @threads);
	my $max_posts=(MAX_POSTS or $posts);
	my $max_size=(MAX_MEGABYTES*1024*1024 or $size);

	while(@threads>$max_threads or $posts>$max_posts or $size>$max_size)
	{
		my $thread=pop @threads;
		read_thread($thread);

		foreach my $num (1..$$thread{postcount})
		{
			my ($image,$thumb)=get_post_images($thread,$num);
			$size-=-s $image;
		}
		$posts-=$$thread{postcount};

		delete_thread($$thread{thread});
	}

	foreach my $thread (@threads)
	{
		close_thread($$thread{thread},1) if(AUTOCLOSE_POSTS and $$thread{postcount}>=AUTOCLOSE_POSTS);
		close_thread($$thread{thread},1) if(AUTOCLOSE_DAYS and (time()-$$thread{lastmod})>=AUTOCLOSE_DAYS*86400);
		close_thread($$thread{thread},1) if(AUTOCLOSE_SIZE and $$thread{size}>=AUTOCLOSE_SIZE*1024);
	}
}

sub delete_post($$$$)
{
	my ($threadnum,$postnum,$password,$fileonly)=@_;
	my $admin_pass=check_admin_pass($password);

	make_error(S_BADDELPASS) unless($password);
	make_error(S_BADDELPASS) unless($admin_pass or match_password($log,$threadnum,$postnum,$password));

	my $reason;
	if($admin_pass) { $reason="mod"; }
	else { $reason="user"; }

	my $thread=read_thread($threadnum);
	return unless $thread;

	if($postnum==1 and !$fileonly)
	{
		if(DELETE_FIRST eq 'remove' or (DELETE_FIRST eq 'single' and $$thread{postcount}==1))
		{ delete_thread($threadnum); return }
	}

	# remove images
	unlink get_post_images($thread,$postnum);

	# remove post
	unless($fileonly)
	{
		set_post_text($thread,$postnum,DELETED_TEMPLATE->(num=>$postnum,reason=>$reason));
		write_thread($thread);
	}
}

sub delete_thread($)
{
	my ($threadnum)=@_;

	make_error(S_UNUSUAL) if($threadnum=~/[^0-9]/); # check to make sure the thread argument is safe

	my $thread=read_thread($threadnum);

	# remove images
	foreach my $num (1..$$thread{postcount}) { unlink get_post_images($thread,$num) }

	unlink $$thread{filename};

	build_pages();
}

sub permasage_thread($$)
{
	my ($threadnum,$state)=@_;

	make_error(S_UNUSUAL) if($threadnum=~/[^0-9]/); # check to make sure the thread argument is safe

	my $thread=read_thread($threadnum);
	$$thread{permasage}=$state;
	write_thread($thread);

	build_pages();
}

sub close_thread($$)
{
	my ($threadnum,$state)=@_;

	make_error(S_UNUSUAL) if($threadnum=~/[^0-9]/); # check to make sure the thread argument is safe

	my $thread=read_thread($threadnum);
	$$thread{closed}=$state;
	write_thread($thread);

	build_pages();
}





#
# Thread access utils
#

sub get_threads($)
{
	my ($bumped)=@_;

	my @pages=map { get_thread($_) } glob(RES_DIR."*".PAGE_EXT);

	if($bumped) { @pages=sort { $$b{lasthit}<=>$$a{lasthit} } @pages; }
	else { @pages=sort { $$b{thread}<=>$$a{thread} } @pages; }

	my $num=1;
	$$_{num}=$num++ for(@pages);

	return @pages;
}

sub get_thread($)
{
	my ($arg)=@_;
	my ($thread,$filename);

	if($arg=~/^[0-9]+$/)
	{
		$thread=$arg;
		$filename=RES_DIR.$thread.PAGE_EXT;
	}
	else
	{
		my $re=RES_DIR.'([0-9]+)'.PAGE_EXT;
		$filename=$arg;
		($thread)=$filename=~/$re/;
	}

	open PAGE,$filename or make_error(S_NOTHREADERR);
	my $head=<PAGE>;
	close PAGE;

	my ($code)=$head=~/\<!--(.*)--\>/;
	return undef unless $code;
	my %meta=%{eval $code};

	$meta{lastmod}=$meta{lasthit} unless $meta{lastmod};

	return {
		%meta,
		thread=>$thread,
		filename=>$filename,
		size=>-s $filename,
	}
}

sub read_thread($)
{
	my $thread=shift;

	$thread=get_thread($thread) or return undef if ref($thread) ne "HASH";
	return $thread if $$thread{allposts};

	my @page=map { s/\r//g; $_ } read_array($$thread{filename});
	return undef unless @page;

	shift @page; # drop metadata
	$$thread{head}=shift @page;
	$$thread{foot}=pop @page;

	my @posts=map +{ text=>$page[$_],num=>$_+1 },(0..$#page);

	$$thread{allposts}=$$thread{posts}=\@posts;

	return $thread;
}

sub get_post_text($$)
{
	my ($thread,$postnum)=@_;
	$thread=read_thread($thread);
	return $$thread{allposts}[$postnum-1]{text};
}

sub set_post_text($$$)
{
	my ($thread,$postnum,$text)=@_;
	$thread=read_thread($thread);
	$$thread{allposts}[$postnum-1]={ text=>$text,num=>$postnum };
	return $thread;
}

sub get_post_images($$)
{
	my ($thread,$postnum)=@_;
	my $post=get_post_text($thread,$postnum);

	my @images;
	my $img_dir=quotemeta IMG_DIR;
	my $thumb_dir=quotemeta THUMB_DIR;

	push @images,$1 if($post=~m!<a [^>]*href="/[^>"]*($img_dir[^>"/]+)"!);
	push @images,$1 if($post=~m!<img [^>]*src="/[^>"]*($thumb_dir[^>"/]+)"!);

	return map { s/\%([0-9a-fA-F]{2})/chr hex $1/ge; $_ } @images;
}

sub filter_post_ranges($$;$)
{
	my ($thread,$ranges,$lines)=@_;

	$thread=read_thread($thread);

	my $nofirst;
	$nofirst=1 if $ranges=~s/^n//i;

	my @postnums;
	my $total=$$thread{postcount};

	foreach my $range (split /,/,$ranges)
	{
		if($range=~/^([0-9]*)-([0-9]*)$/)
		{
			my $start=($1 or 1);
			my $end=($2 or $total);

			$start=$total if $start>$total;
			$end=$total if $end>$total;

			if($start<$end) { push @postnums,($start..$end) }
			else { push @postnums,reverse ($end..$start) }
		}
		elsif($range=~/^([0-9]+)$/)
		{
			my $post=$1;
			push @postnums,$post if $post>0 and $post<=$total;
		}
		elsif($range=~/^l([0-9]+)$/i)
		{
			my $start=$total-$1+1;
			$start=1 if $start<1;
			push @postnums,($start..$total);
		}
		elsif($range=~/^r([0-9]{1,4})$/i)
		{
			my $num=($1 or 1);
			push @postnums,int (rand $total)+1 for(1..$num);
		}
		elsif($range=~/^q([0-9]+)$/i)
		{
			my $num=$1;

			push @postnums,$num;
			OUTER: foreach my $post (1..$total)
			{
				next if $post eq $num;
				my $text=get_post_text($thread,$post);
				while($text=~/&gt;&gt;($replyrange_re)/g)
				{
					if(in_range($num,$1)) { push @postnums,$post; next OUTER; }
				}
			}
		}
	}

	@postnums=@postnums[0..999] if @postnums>1000;
	@postnums=(1..$total) unless @postnums;

	if($ranges=~/^[0-9]*-[0-9]*$/ or $ranges=~/^l[0-9]+$/i)
	{
		my $start=$postnums[0];
		my $end=$postnums[$#postnums];

		if($start<=$end)
		{
			$$thread{prevpost}=$start-1 unless $start<=1;
			$$thread{nextpost}=$end+1 unless $end>=$total;
			unshift @postnums,1 unless $nofirst or $start==1;
		}
	}

	# fix up and abbreviate posts
	my @posts=map {
		my %post;
		my $text=get_post_text($thread,$_);

		$post{text}=$text;
		$post{num}=$_;

		if($lines)
		{
			my $abbrev=abbreviate_post($text,$lines);
			$post{abbreviation}=$abbrev||$text;
			$post{abbreviated}=$abbrev?1:0;
		}
		else
		{
			$post{text}=$text;
		}

		\%post;
	} @postnums;

	$$thread{posts}=\@posts;

	return $thread;
}

sub abbreviate_post($$)
{
	my ($post,$lines)=@_;

#	if($post=~m!^(.*?<div class="replytext">)(.*?)(</div>.*$)!s)
#	{
#		my ($prefix,$comment,$postfix)=($1,$2,$3);
#
#		my $abbrev=abbreviate_html($comment,$lines,APPROX_LINE_LENGTH);
#		return $prefix.$abbrev.$postfix if($abbrev);
#	}
#	else
#	{
		my $abbrev=abbreviate_html($post,$lines,APPROX_LINE_LENGTH);
		return $abbrev if($abbrev);
#	}

	return undef;
}

sub in_range($$)
{
	my ($num,$ranges)=@_;

	foreach my $range (split /(,|&#44;)/,$ranges)
	{
		if($range=~/^([0-9]*)-([0-9]*)$/)
		{
			my $start=($1 or 1);
			my $end=($2 or 1000000); # arbitary large number

			($start,$end)=($end,$start) if($start>$end);

			return 1 if($num>=$start and $num<=$end);
		}
		elsif($range=~/^([0-9]+)$/)
		{
			return 1 if($num==$1);
		}
		#elsif($range=~/^l([0-9]+)$/i) {} # l ranges never match
		#elsif($range=~/^r([0-9]*)$/i) {} # r ranges never match
		#elsif($range=~/^q([0-9]+)$/i) {} # q ranges never match
	}
	return 0;
}

sub update_thread($)
{
	my $thread=shift;

}

sub write_thread($)
{
	my $thread=shift;

	my @written=("postcount","author","title","lasthit","lastmod","permasage","closed");
	my %meta;
	@meta{@written}=@{$thread}{@written};

	my @page;
	$Data::Dumper::Terse=1;
	$Data::Dumper::Indent=0;
	push @page,'<!-- '.Dumper(\%meta).' -->';
	push @page,THREAD_HEAD_TEMPLATE->(%{$thread});
	push @page,map { get_post_text($thread,$_) } 1..$$thread{postcount};
	push @page,THREAD_FOOT_TEMPLATE->(%{$thread});

	write_array($$thread{filename},@page);
}

sub make_thread($$$)
{
	my ($title,$time,$author)=@_;
	my $filename=RES_DIR.$time.PAGE_EXT;

	make_error(S_THREADCOLL) if(-e $filename);

	write_thread({
		thread=>$time,
		filename=>$filename,
		title=>$title,
		postcount=>0,
		lasthit=>$time,
		lastmod=>$time,
		permasage=>0,
		closed=>0,
		author=>$author,
		head=>"",
		foot=>"",
		posts=>[],
		allposts=>[],
	});

	return $time;
}




#
# Log fuctions
#

sub match_password($$$$)
{
	my ($log,$thread,$post,$password)=@_;
	my $encpass=hide_password($password);

	return 0 unless(ENABLE_DELETION);

	foreach(@{$log})
	{
		my @data=split /\s*,\s*/;
		if($data[0]==$thread and $data[1]==$post)
		{
 			return 1 if($data[2] eq $encpass or decrypt_string($data[2],"cryptpass") eq $encpass);
 		}
	}
	return 0;
}

sub find_key($$)
{
	my ($log,$key)=@_;

	foreach(@{$log})
	{
		my @data=split /\s*,\s*/;
		return 1 if($data[4] eq $key);
	}
	return 0;
}

sub find_md5($$)
{
	my ($log,$md5)=@_;

	foreach(@{$log})
	{
		my @data=split /\s*,\s*/;
		return ($data[0],$data[1]) if($data[5] eq $md5 and -e $data[6]);
	}
	return ();
}

sub lock_log()
{
	open LOGFILE,"+>>".LOG_FILE or make_error(S_NOLOG);
	eval "flock LOGFILE,LOCK_EX"; # may not work on some platforms - ignore it if it does not.
	seek LOGFILE,0,0;

	my @log=grep { /^([0-9]+)/; -e RES_DIR.$1.PAGE_EXT } read_array(\*LOGFILE);

	# should remove MD5 for deleted files somehow
	return \@log;
}

sub release_log(;$)
{
	my ($log)=@_;

	if($log)
	{
		seek LOGFILE,0,0;
		truncate LOGFILE,0;
		write_array(\*LOGFILE,@$log);
	}

	close LOGFILE;
}

sub add_log($$$$$$$)
{
	my ($log,$thread,$post,$password,$ip,$key,$md5,$file)=@_;

	$password=encrypt_string(hide_password($password),"cryptpass");
	$ip=encrypt_string($ip,"ip");

	unshift @$log,"$thread,$post,$password,$ip,$key,$md5,$file";
}

sub hide_password($)
{
	return hide_data(shift,6,"password",SECRET,1)
}

sub encrypt_string($$)
{
	my ($str,$key)=@_;
	my $iv=make_random_string(8);
	return $iv.';'.encode_base64(rc4($str,make_key($key,SECRET,32).$iv),"");
}

sub decrypt_string($$)
{
	my ($str,$key)=@_;
	my ($iv,$crypt)=$str=~/(.*?);(.*)/;
	return rc4(decode_base64($crypt),make_key($key,SECRET,32).$iv);
}



#
# Utility funtions
#

sub get_stylesheets()
{
	my $found=0;
	my @stylesheets=map
	{
		my %sheet;

		$sheet{filename}=$_;

		($sheet{title})=m!([^/]+)\.css$!i;
		$sheet{title}=ucfirst $sheet{title};
		$sheet{title}=~s/_/ /g;
		$sheet{title}=~s/ ([a-z])/ \u$1/g;
		$sheet{title}=~s/([a-z])([A-Z])/$1 $2/g;

		if($sheet{title} eq DEFAULT_STYLE) { $sheet{default}=1; $found=1; }
		else { $sheet{default}=0; }

		\%sheet;
	} glob(CSS_DIR."*.css");

	$stylesheets[0]{default}=1 if(@stylesheets and !$found);

	return \@stylesheets;
}

sub check_admin_pass($)
{
	my $password=shift;
	return 1 if $password eq ADMIN_PASS;
	return 1 if $password eq encode_admin_pass(ADMIN_PASS);
	return 0;
}

sub encode_admin_pass($)
{
	my $crypt=hide_data((shift).$ENV{REMOTE_ADDR},9,"admin",SECRET,1);
	$crypt=~tr/+/./; # for web shit
	return $crypt;
}



#
# Error handling
#

sub make_error($)
{
	my ($error)=@_;

	print "Content-Type: ".get_xhtml_content_type(CHARSET,USE_XHTML)."\n";
	print "\n";
	print ERROR_TEMPLATE->(error=>$error);
	exit 0;
}



#
# Image handling
#

sub get_filetypes()
{
	my %filetypes=FILETYPES;
	$filetypes{gif}=$filetypes{jpg}=$filetypes{png}=1;
	return join ", ",map { uc } sort keys %filetypes;
}

sub process_file($$$)
{
	my ($file,$uploadname,$time)=@_;
	my %filetypes=FILETYPES;

	# find out the file size
	my $size=-s $file;

	make_error(S_TOOBIG) if($size>MAX_KB*1024);
	make_error(S_EMPTY) if($size==0);

	# make sure to read file in binary mode on platforms that care about such things
	binmode $file;

	# analyze file and check that it's in a supported format
	my ($ext,$width,$height)=analyze_image($file,$uploadname);

	my $known=$width || $filetypes{$ext};

	make_error(S_BADFORMAT) unless(ALLOW_UNKNOWN or $known);
	make_error(S_BADFORMAT) if(grep { $_ eq $ext } FORBIDDEN_EXTENSIONS);
	make_error(S_TOOBIG) if(MAX_IMAGE_WIDTH and $width>MAX_IMAGE_WIDTH);
	make_error(S_TOOBIG) if(MAX_IMAGE_HEIGHT and $height>MAX_IMAGE_HEIGHT);
	make_error(S_TOOBIG) if(MAX_IMAGE_PIXELS and $width*$height>MAX_IMAGE_PIXELS);

	# generate random filename - fudges the microseconds
	my $filebase=$time.sprintf("%03d",int(rand(1000)));
	my $filename=IMG_DIR.$filebase.'.'.$ext;
	my $thumbnail=THUMB_DIR.$filebase."s.jpg";
	$filename.=MUNGE_UNKNOWN unless($known);

	# do copying and MD5 checksum
	my ($md5,$md5ctx,$buffer);

	# prepare MD5 checksum if the Digest::MD5 module is available
	eval 'use Digest::MD5 qw(md5_hex)';
	$md5ctx=Digest::MD5->new unless($@);

	# copy file
	open (OUTFILE,">>$filename") or make_error(S_NOTWRITE);
	binmode OUTFILE;
	while (read($file,$buffer,1024)) # should the buffer be larger?
	{
		print OUTFILE $buffer;
		$md5ctx->add($buffer) if($md5ctx);
	}
	close $file;
	close OUTFILE;

	if($md5ctx) # if we have Digest::MD5, get the checksum
	{
		$md5=$md5ctx->hexdigest();
	}
	else # otherwise, try using the md5sum command
	{
		my $md5sum=`md5sum $filename`; # filename is always the timestamp name, and thus safe
		($md5)=$md5sum=~/^([0-9a-f]+)/ unless($?);
	}

	if($md5) # if we managed to generate an md5 checksum, check for duplicate files
	{
		my ($thread,$post)=find_md5($log,$md5);
		if($thread)
		{
			unlink $filename; # make sure to remove the file
			make_error(sprintf S_DUPE,"$ENV{SCRIPT_NAME}/$thread/$post");
		}
	}

	# do thumbnail
	my ($tn_width,$tn_height,$tn_ext);

	if(!$width) # unsupported file
	{
		if($filetypes{$ext}) # externally defined filetype
		{
			open THUMBNAIL,$filetypes{$ext};
			binmode THUMBNAIL;
			($tn_ext,$tn_width,$tn_height)=analyze_image(\*THUMBNAIL,$filetypes{$ext});
			close THUMBNAIL;

			# was that icon file really there?
			if(!$tn_width) { $thumbnail=undef }
			else { $thumbnail=$filetypes{$ext} }
		}
		else
		{
			$thumbnail=undef;
		}
	}
	elsif($width>MAX_W or $height>MAX_H or THUMBNAIL_SMALL)
	{
		if($width<=MAX_W and $height<=MAX_H)
		{
			$tn_width=$width;
			$tn_height=$height;
		}
		else
		{
			$tn_width=MAX_W;
			$tn_height=int(($height*(MAX_W))/$width);

			if($tn_height>MAX_H)
			{
				$tn_width=int(($width*(MAX_H))/$height);
				$tn_height=MAX_H;
			}
		}

		if(STUPID_THUMBNAILING) { $thumbnail=$filename }
		else
		{
			$thumbnail=undef unless(make_thumbnail($filename,$thumbnail,$tn_width,$tn_height,THUMBNAIL_QUALITY,CONVERT_COMMAND));
		}
	}
	else
	{
		$tn_width=$width;
		$tn_height=$height;
		$thumbnail=$filename;
	}

	if($filetypes{$ext}) # externally defined filetype - restore the name
	{
		my $newfilename=$uploadname;
		$newfilename=~s!^.*[\\/]!!; # cut off any directory in filename
		$newfilename=IMG_DIR.$newfilename;

		unless(-e $newfilename) # verify no name clash
		{
			rename $filename,$newfilename;
			$filename=$newfilename;
		}
		else
		{
			unlink $filename;
			make_error(S_DUPENAME);
		}
	}

	return ($filename,$ext,$size,$md5,$width,$height,$thumbnail,$tn_width,$tn_height);
}
