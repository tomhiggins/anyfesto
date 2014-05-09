# wakautils.pl v8.12

use strict;

use Time::Local;
use Socket;

my $has_md5=0;
eval 'use Digest::MD5 qw(md5)';
$has_md5=1 unless $@;

my $has_encode=0;
eval 'use Encode qw(decode)';
$has_encode=1 unless $@;


use constant MAX_UNICODE => 1114111;

#
# HTML utilities
#

my $protocol_re=qr{(?:http://|https://|ftp://|mailto:|news:|irc:)};
my $url_re=qr{(${protocol_re}[^\s<>()"]*?(?:\([^\s<>()"]*?\)[^\s<>()"]*?)*)((?:\s|<|>|"|\.||\]|!|\?|,|&#44;|&quot;)*(?:[\s<>()"]|$))};

sub protocol_regexp() { return $protocol_re }

sub url_regexp() { return $url_re }

sub abbreviate_html($$$)
{
	my ($html,$max_lines,$approx_len)=@_;
	my ($lines,$chars,@stack);

	return undef unless($max_lines);

	while($html=~m!(?:([^<]+)|<(/?)(\w+).*?(/?)>)!g)
	{
		my ($text,$closing,$tag,$implicit)=($1,$2,lc($3),$4);

		if($text) { $chars+=length $text; }
		else
		{
			push @stack,$tag if(!$closing and !$implicit);
			pop @stack if($closing);

			if(($closing or $implicit) and ($tag eq "p" or $tag eq "blockquote" or $tag eq "pre"
			or $tag eq "li" or $tag eq "ol" or $tag eq "ul" or $tag eq "br"))
			{
				$lines+=int($chars/$approx_len)+1;
				$lines++ if($tag eq "p" or $tag eq "blockquote");
				$chars=0;
			}

			if($lines>=$max_lines)
			{
 				# check if there's anything left other than end-tags
 				return undef if (substr $html,pos $html)=~m!^(?:\s*</\w+>)*\s*$!s;

				my $abbrev=substr $html,0,pos $html;
				while(my $tag=pop @stack) { $abbrev.="</$tag>" }

				return $abbrev;
			}
		}
	}

	return undef;
}

sub sanitize_html($%)
{
	my ($html,%tags)=@_;
	my (@stack,$clean);
	my $entity_re=qr/&(?!\#[0-9]+;|\#x[0-9a-fA-F]+;|amp;|lt;|gt;)/;

	while($html=~/(?:([^<]+)|<([^<>]*)>|(<))/sg)
	{
		my ($text,$tag,$lt)=($1,$2,$3);

		if($lt)
		{
			$clean.="&lt;";
		}
		elsif($text)
		{
			$text=~s/$entity_re/&amp;/g;
			$text=~s/>/&gt;/g;
			$clean.=$text;
		}
		else
		{
			if($tag=~m!^\s*(/?)\s*([a-z0-9_:\-\.]+)(?:\s+(.*?)|)\s*(/?)\s*$!si)
			{
				my ($closing,$name,$args,$implicit)=($1,lc($2),$3,$4);

				if($tags{$name})
				{
					if($closing)
					{
						if(grep { $_ eq $name } @stack)
						{
							my $entry;

							do {
								$entry=pop @stack;
								$clean.="</$entry>";
							} until $entry eq $name;
						}
					}
					else
					{
						my %args;

						$args=~s/\s/ /sg;

						while($args=~/([a-z0-9_:\-\.]+)(?:\s*=\s*(?:'([^']*?)'|"([^"]*?)"|['"]?([^'" ]*))|)/gi)
						{
							my ($arg,$value)=(lc($1),defined($2)?$2:defined($3)?$3:$4);
							$value=$arg unless defined($value);

							my $type=$tags{$name}{args}{$arg};

							if($type)
							{
								my $passes=1;

								if($type=~/url/i) { $passes=0 unless $value=~/(?:^${protocol_re}|^[^:]+$)/ }
								if($type=~/number/i) { $passes=0 unless $value=~/^[0-9]+$/  }

								if($passes)
								{
									$value=~s/$entity_re/&amp;/g;
									$args{$arg}=$value;
								}
							}
						}

						$args{$_}=$tags{$name}{forced}{$_} for (keys %{$tags{$name}{forced}}); # override forced arguments

						my $cleanargs=join " ",map {
							my $value=$args{$_};
							$value=~s/'/%27/g;
							"$_='$value'";
						} keys %args;

						$implicit="/" if($tags{$name}{empty});

						push @stack,$name unless $implicit;

						$clean.="<$name";
						$clean.=" $cleanargs" if $cleanargs;
						#$clean.=" $implicit" if $implicit;
						$clean.=">";
						$clean.="</$name>" if $implicit;
					}
				}
			}
		}
	}

	my $entry;
	while($entry=pop @stack) { $clean.="</$entry>" }

	return $clean;
}

sub describe_allowed(%)
{
	my (%tags)=@_;

	return join ", ",map { $_.($tags{$_}{args}?" (".(join ", ",sort keys %{$tags{$_}{args}}).")":"") } sort keys %tags;
}

sub do_wakabamark($;$$)
{
	my ($text,$handler,$simplify)=@_;
	my $res;

	my @lines=split /(?:\r\n|\n|\r)/,$text;

	while(defined($_=$lines[0]))
	{
		if(/^\s*$/) { shift @lines; } # skip empty lines
		elsif(/^(1\.|[\*\+\-]) /) # lists
		{
			my ($tag,$re,$skip,$html);

			if($1 eq "1.") { $tag="ol"; $re=qr/[0-9]+\./; $skip=1; }
			else { $tag="ul"; $re=qr/\Q$1\E/; $skip=0; }

			while($lines[0]=~/^($re)(?: |\t)(.*)/)
			{
				my $spaces=(length $1)+1;
				my $item="$2\n";
				shift @lines;

				while($lines[0]=~/^(?: {1,$spaces}|\t)(.*)/) { $item.="$1\n"; shift @lines }
				$html.="<li>".do_wakabamark($item,$handler,1)."</li>";

				if($skip) { while(@lines and $lines[0]=~/^\s*$/) { shift @lines; } } # skip empty lines
			}
			$res.="<$tag>$html</$tag>";
		}
		elsif(/^(?:    |\t)/) # code sections
		{
			my @code;
			while($lines[0]=~/^(?:    |\t)(.*)/) { push @code,$1; shift @lines; }
			$res.="<pre><code>".(join "<br />",@code)."</code></pre>";
		}
		elsif(/^&gt;/) # quoted sections
		{
			my @quote;
			while($lines[0]=~/^(&gt;.*)/) { push @quote,$1; shift @lines; }
			$res.="<blockquote>".do_spans($handler,@quote)."</blockquote>";

			#while($lines[0]=~/^&gt;(.*)/) { push @quote,$1; shift @lines; }
			#$res.="<blockquote>".do_blocks($handler,@quote)."</blockquote>";
		}
		else # normal paragraph
		{
			my @text;
			while($lines[0]!~/^(?:\s*$|1\. |[\*\+\-] |&gt;|    |\t)/) { push @text,shift @lines; }
			if(!defined($lines[0]) and $simplify) { $res.=do_spans($handler,@text) }
			else { $res.="<p>".do_spans($handler,@text)."</p>" }
		}
		$simplify=0;
	}

	return $res;
}

sub do_spans($@)
{
	my $handler=shift;
	return join "<br />",map
	{
		my $line=$_;
		my @hidden;

		# hide <code> sections
		$line=~s{ (?<![\x80-\x9f\xe0-\xfc]) (`+) ([^<>]+?) (?<![\x80-\x9f\xe0-\xfc]) \1}{push @hidden,"<code>$2</code>"; "<!--$#hidden-->"}sgex;

		# make URLs into links and hide them
		$line=~s{$url_re}{push @hidden,"<a href=\"$1\" rel=\"nofollow\">$1\</a>"; "<!--$#hidden-->$2"}sge;

		# do <strong>
		$line=~s{ (?<![0-9a-zA-Z\*_\x80-\x9f\xe0-\xfc]) (\*\*|__) (?![<>\s\*_]) ([^<>]+?) (?<![<>\s\*_\x80-\x9f\xe0-\xfc]) \1 (?![0-9a-zA-Z\*_]) }{<strong>$2</strong>}gx;

		# do <em>
		$line=~s{ (?<![0-9a-zA-Z\*_\x80-\x9f\xe0-\xfc]) (\*|_) (?![<>\s\*_]) ([^<>]+?) (?<![<>\s\*_\x80-\x9f\xe0-\xfc]) \1 (?![0-9a-zA-Z\*_]) }{<em>$2</em>}gx;

		# do ^H
		if($]>5.007)
		{
			my $regexp;
			$regexp=qr/(?:&#?[0-9a-zA-Z]+;|[^&<>])(?<!\^H)(??{$regexp})?\^H/;
			$line=~s{($regexp)}{"<del>".(substr $1,0,(length $1)/3)."</del>"}gex;
		}

		$line=$handler->($line) if($handler);

		# fix up hidden sections
		$line=~s{<!--([0-9]+)-->}{$hidden[$1]}ge;

		$line;
	} @_;
}

sub compile_template($;$)
{
	my ($str,$nostrip)=@_;
	my $code;

	unless($nostrip)
	{
		$str=~s/^\s+//;
		$str=~s/\s+$//;
		$str=~s/\n\s*/ /sg;
	}

	while($str=~m!(.*?)(<(/?)(var|const|if|loop)(?:|\s+(.*?[^\\]))>|$)!sg)
	{
		my ($html,$tag,$closing,$name,$args)=($1,$2,$3,$4,$5);

		$html=~s/(['\\])/\\$1/g;
		$code.="\$res.='$html';" if(length $html);
		$args=~s/\\>/>/g;

		if($tag)
		{
			if($closing)
			{
				if($name eq 'if') { $code.='}' }
				elsif($name eq 'loop') { $code.='$$_=$__ov{$_} for(keys %__ov);}}' }
			}
			else
			{
				if($name eq 'var') { $code.='$res.=eval{'.$args.'};' }
				elsif($name eq 'const') { my $const=eval $args; $const=~s/(['\\])/\\$1/g; $code.='$res.=\''.$const.'\';' }
				elsif($name eq 'if') { $code.='if(eval{'.$args.'}){' }
				elsif($name eq 'loop')
				{ $code.='my $__a=eval{'.$args.'};if($__a){for(@$__a){my %__v=%{$_};my %__ov;for(keys %__v){$__ov{$_}=$$_;$$_=$__v{$_};}' }
			}
		}
	}

	my $sub=eval
		'no strict; sub { '.
		'my $port=$ENV{SERVER_PORT}==80?"":":$ENV{SERVER_PORT}";'.
		'my $self=$ENV{SCRIPT_NAME};'.
		'my $absolute_self="http://$ENV{SERVER_NAME}$port$ENV{SCRIPT_NAME}";'.
		'my ($path)=$ENV{SCRIPT_NAME}=~m!^(.*/)[^/]+$!;'.
		'my $absolute_path="http://$ENV{SERVER_NAME}$port$path";'.
		'my %__v=@_;my %__ov;for(keys %__v){$__ov{$_}=$$_;$$_=$__v{$_};}'.
		'my $res;'.
		$code.
		'$$_=$__ov{$_} for(keys %__ov);'.
		'return $res; }';

	die "Template format error" unless $sub;

	return $sub;
}

sub template_for($$$)
{
	my ($var,$start,$end)=@_;
	return [map +{$var=>$_},($start..$end)];
}

sub include($)
{
	my ($filename)=@_;

	open FILE,$filename or return '';
	my $file=do { local $/; <FILE> };

	$file=~s/^\s+//;
	$file=~s/\s+$//;
	$file=~s/\n\s*/ /sg;

	return $file;
}


sub forbidden_unicode($;$)
{
	my ($dec,$hex)=@_;
	return 1 if length($dec)>7 or length($hex)>7; # too long numbers
	my $ord=($dec or hex $hex);

	return 1 if $ord>MAX_UNICODE; # outside unicode range
	return 1 if $ord<32; # control chars
	return 1 if $ord>=0x7f and $ord<=0x84; # control chars
	return 1 if $ord>=0xd800 and $ord<=0xdfff; # surrogate code points
	return 1 if $ord>=0x202a and $ord<=0x202e; # text direction
	return 1 if $ord>=0xfdd0 and $ord<=0xfdef; # non-characters
	return 1 if $ord % 0x10000 >= 0xfffe; # non-characters
	return 0;
}

sub clean_string($;$)
{
	my ($str,$cleanentities)=@_;

	if($cleanentities) { $str=~s/&/&amp;/g } # clean up &
	else
	{
		$str=~s/&(#([0-9]+);|#x([0-9a-fA-F]+);|)/
			if($1 eq "") { '&amp;' } # change simple ampersands
			elsif(forbidden_unicode($2,$3))  { "" } # strip forbidden unicode chars
			else { "&$1" } # and leave the rest as-is.
		/ge  # clean up &, excluding numerical entities
	}

	$str=~s/\</&lt;/g; # clean up brackets for HTML tags
	$str=~s/\>/&gt;/g;
	$str=~s/"/&quot;/g; # clean up quotes for HTML attributes
	$str=~s/'/&#39;/g;
	$str=~s/,/&#44;/g; # clean up commas for some reason I forgot

	$str=~s/[\x00-\x08\x0b\x0c\x0e-\x1f]//g; # remove control chars

	return $str;
}

sub decode_string($;$$)
{
	my ($str,$charset,$noentities)=@_;
	my $use_unicode=$has_encode && $charset;

	$str=decode($charset,$str) if $use_unicode;

	$str=~s{(&#([0-9]*)([;&])|&#([x&])([0-9a-f]*)([;&]))}{
		my $ord=($2 or hex $5);
		if($3 eq '&' or $4 eq '&' or $5 eq '&') { $1 } # nested entities, leave as-is.
		elsif(forbidden_unicode($2,$5))  { "" } # strip forbidden unicode chars
		elsif($ord==35 or $ord==38) { $1 } # don't convert & or #
		elsif($use_unicode) { chr $ord } # if we have unicode support, convert all entities
		elsif($ord<128) { chr $ord } # otherwise just convert ASCII-range entities
		else { $1 } # and leave the rest as-is.
	}gei unless $noentities;

	$str=~s/[\x00-\x08\x0b\x0c\x0e-\x1f]//g; # remove control chars

	return $str;
}

sub escamp($)
{
	my ($str)=@_;
	$str=~s/&/&amp;/g;
	return $str;
}

sub urlenc($)
{
	my ($str)=@_;
	$str=~s/([^\w ])/"%".sprintf("%02x",ord $1)/sge;
	$str=~s/ /+/sg;
	return $str;
}

sub clean_path($)
{
	my ($str)=@_;
	$str=~s!([^\w/._\-])!"%".sprintf("%02x",ord $1)!sge;
	return $str;
}



#
# Javascript utilities
#

sub clean_to_js($)
{
	my $str=shift;

	$str=~s/&amp;/\\x26/g;
	$str=~s/&lt;/\\x3c/g;
	$str=~s/&gt;/\\x3e/g;
	$str=~s/&quot;/\\x22/g; #"
	$str=~s/(&#39;|')/\\x27/g;
	$str=~s/&#44;/,/g;
	$str=~s/&#[0-9]+;/sprintf "\\u%04x",$1/ge;
	$str=~s/&#x[0-9a-f]+;/sprintf "\\u%04x",hex($1)/gie;
	$str=~s/(\r\n|\r|\n)/\\n/g;

	return "'$str'";
}

sub js_string($)
{
	my $str=shift;

	$str=~s/\\/\\\\/g;
	$str=~s/'/\\'/g;
	$str=~s/([\x00-\x1f\x80-\xff<>&])/sprintf "\\x%02x",ord($1)/ge;
	eval '$str=~s/([\x{100}-\x{ffff}])/sprintf "\\u%04x",ord($1)/ge';
	$str=~s/(\r\n|\r|\n)/\\n/g;

	return "'$str'";
}

sub js_array(@)
{
	return "[".(join ",",@_)."]";
}

sub js_hash(%)
{
	my %hash=@_;
	return "{".(join ",",map "'$_':$hash{$_}",keys %hash)."}";
}


#
# HTTP utilities
#

# LIGHTWEIGHT HTTP/1.1 CLIENT
# by fatalM4/coda, modified by WAHa.06x36

use constant CACHEFILE_PREFIX => 'cache-'; # you can make this a directory (e.g. 'cachedir/cache-' ) if you'd like
use constant FORCETIME => '0.04'; 	# If the cache is less than (FORCETIME) days old, don't even attempt to refresh.
                                    # Saves everyone some bandwidth. 0.04 days is ~ 1 hour. 0.0007 days is ~ 1 min.
eval 'use IO::Socket::INET'; # Will fail on old Perl versions!

sub get_http($;$$$)
{
	my ($url,$maxsize,$referer,$cacheprefix)=@_;
	my ($host,$port,$doc)=$url=~m!^(?:http://|)([^/]+)(:[0-9]+|)(.*)$!;
	$port=80 unless($port);

	my $hash=encode_base64(rc4(null_string(6),"$host:$port$doc",0),"");
	$hash=~tr!/+!_-!; # remove / and +
	my $cachefile=($cacheprefix or CACHEFILE_PREFIX).($doc=~m!([^/]{0,15})$!)[0]."-$hash"; # up to 15 chars of filename
	my ($modified,$cache);

	if(open CACHE,"<",$cachefile)  # get modified date and cache contents
	{
		$modified=<CACHE>;
		$cache=join "",<CACHE>;
		chomp $modified;
		close CACHE;

		return $cache if((-M $cachefile)<FORCETIME);
	}

	my $sock=IO::Socket::INET->new("$host:$port") or return $cache;
	print $sock "GET $doc HTTP/1.1\r\nHost: $host\r\nConnection: close\r\n";
	print $sock "If-Modified-Since: $modified\r\n" if $modified;
	print $sock "Referer: $referer\r\n" if $referer;
	print $sock "\r\n"; #finished!

	# header
	my ($line,$statuscode,$lastmod);
	do {
		$line=<$sock>;
		$statuscode=$1 if($line=~/^HTTP\/1\.1 (\d+)/);
		$lastmod=$1 if($line=~/^Last-Modified: (.*)/);
	} until ($line=~/^\r?\n/);

	# body
	my ($line,$output);
	while($line=<$sock>)
	{
		$output.=$line;
		last if $maxsize and $output>=$maxsize;
	}
	undef $sock;

	if($statuscode=="200")
	{
		#navbar changed, update cache
		if(open CACHE,">$cachefile")
		{
			print CACHE "$lastmod\n";
			print CACHE $output;
			close CACHE or die "close cache: $!";
		}
		return $output;
	}
	else # touch and return cache, or nothing if no cache
	{
		utime(time,time,$cachefile);
		return $cache;
	}
}

sub make_http_forward($;$)
{
	my ($location,$alternate_method)=@_;

	if($alternate_method)
	{
		print "Content-Type: text/html\n";
		print "\n";
		print "<html><head>";
		print '<meta http-equiv="refresh" content="0; url='.$location.'" />';
		print '<script type="text/javascript">document.location="'.$location.'";</script>';
		print '</head><body><a href="'.$location.'">'.$location.'</a></body></html>';
	}
	else
	{
		print "Status: 303 Go West\n";
		print "Location: $location\n";
		print "Content-Type: text/html\n";
		print "\n";
		print '<html><body><a href="'.$location.'">'.$location.'</a></body></html>';
	}
}

sub make_cookies(%)
{
	my (%cookies)=@_;

	my $charset=$cookies{'-charset'};
	my $expires=($cookies{'-expires'} or time+14*24*3600);
	my $autopath=$cookies{'-autopath'};
	my $path=$cookies{'-path'};

	my $date=make_date($expires,"cookie");

	unless($path)
	{
		if($autopath eq 'current') { ($path)=$ENV{SCRIPT_NAME}=~m!^(.*/)[^/]+$! }
		elsif($autopath eq 'parent') { ($path)=$ENV{SCRIPT_NAME}=~m!^(.*?/)(?:[^/]+/)?[^/]+$! }
		else { $path='/'; }
	}

	foreach my $name (keys %cookies)
	{
		next if($name=~/^-/); # skip entries that start with a dash

		my $value=$cookies{$name};
		$value="" unless(defined $value);

		$value=cookie_encode($value,$charset);

		print "Set-Cookie: $name=$value; path=$path; expires=$date;\n";
	}
}

sub cookie_encode($;$)
{
	my ($str,$charset)=@_;

	if($]>5.007) # new perl, use Encode.pm
	{
		if($charset)
		{
			require Encode;
			$str=Encode::decode($charset,$str);
			$str=~s/&\#([0-9]+);/chr $1/ge;
			$str=~s/&\#x([0-9a-f]+);/chr hex $1/gei;
		}

		$str=~s/([^0-9a-zA-Z])/
			my $c=ord $1;
			sprintf($c>255?'%%u%04x':'%%%02x',$c);
		/sge;
	}
	else # do the hard work ourselves
	{
		if($charset=~/\butf-?8$/i)
		{
			$str=~s{([\xe0-\xef][\x80-\xBF][\x80-\xBF]|[\xc0-\xdf][\x80-\xBF]|&#([0-9]+);|&#[xX]([0-9a-fA-F]+);|[^0-9a-zA-Z])}{ # convert UTF-8 to URL encoding - only handles up to U-FFFF
				my $c;
				if($2) { $c=$2 }
				elsif($3) { $c=hex $3 }
				elsif(length $1==1) { $c=ord $1 }
				elsif(length $1==2)
				{
					my @b=map { ord $_ } split //,$1;
					$c=(($b[0]-0xc0)<<6)+($b[1]-0x80);
				}
				elsif(length $1==3)
				{
					my @b=map { ord $_ } split //,$1;
					$c=(($b[0]-0xe0)<<12)+(($b[1]-0x80)<<6)+($b[2]-0x80);
				}
				sprintf($c>255?'%%u%04x':'%%%02x',$c);
			}sge;
		}
		elsif($charset=~/\b(?:shift.*jis|sjis)$/i) # old perl, using shift_jis
		{
			require 'sjis.pl';
			my $sjis_table=get_sjis_table();

			$str=~s{([\x80-\x9f\xe0-\xfc].|&#([0-9]+);|&#[xX]([0-9a-fA-F]+);|[^0-9a-zA-Z])}{ # convert Shift_JIS to URL encoding
				my $c=($2 or ($3 and hex $3) or $$sjis_table{$1});
				sprintf($c>255?'%%u%04x':'%%%02x',$c);
			}sge;
		}
		else
		{
			$str=~s/([^0-9a-zA-Z])/sprintf('%%%02x',ord $1)/sge;
		}
	}

	return $str;
}

sub get_xhtml_content_type(;$$)
{
	my ($charset,$usexhtml)=@_;
	my $type;

	if($usexhtml and $ENV{HTTP_ACCEPT}=~/application\/xhtml\+xml/) { $type="application/xhtml+xml"; }
	else { $type="text/html"; }

	$type.="; charset=$charset" if($charset);

	return $type;
}

sub expand_filename($)
{
	my ($filename)=@_;
	return $filename if($filename=~m!^/!);
	return $filename if($filename=~m!^\w+:!);

	my ($self_path)=$ENV{SCRIPT_NAME}=~m!^(.*/)[^/]+$!;
	return $self_path.$filename;
}

#
# Network utilities
#

sub resolve_host($)
{
	my $ip=shift;
	return (gethostbyaddr inet_aton($ip),AF_INET or $ip);
}


#
# Data utilities
#

sub process_tripcode($;$$$$)
{
	my ($name,$tripkey,$secret,$charset,$nonamedecoding)=@_;
	$tripkey="!" unless($tripkey);

	if($name=~/^(.*?)((?<!&)#|\Q$tripkey\E)(.*)$/)
	{
		my ($namepart,$marker,$trippart)=($1,$2,$3);
		my $trip;
	
		$namepart=decode_string($namepart,$charset) unless $nonamedecoding;
		$namepart=clean_string($namepart);

		if($secret and $trippart=~s/(?:\Q$marker\E)(?<!&#)(?:\Q$marker\E)*(.*)$//) # do we want secure trips, and is there one?
		{
			my $str=$1;
			my $maxlen=255-length($secret);
			$str=substr $str,0,$maxlen if(length($str)>$maxlen);
#			$trip=$tripkey.$tripkey.encode_base64(rc4(null_string(6),"t".$str.$secret),"");
			$trip=$tripkey.$tripkey.hide_data($1,6,"trip",$secret,1);
			return ($namepart,$trip) unless($trippart); # return directly if there's no normal tripcode
		}

		# 2ch trips are processed as Shift_JIS whenever possible
		eval 'use Encode qw(decode encode)';
		unless($@)
		{
			$trippart=decode_string($trippart,$charset);
			$trippart=encode("Shift_JIS",$trippart,0x0200);
		}

		$trippart=clean_string($trippart);
		my $salt=substr $trippart."H..",1,2;
		$salt=~s/[^\.-z]/./g;
		$salt=~tr/:;<=>?@[\\]^_`/ABCDEFGabcdef/; 
		$trip=$tripkey.(substr crypt($trippart,$salt),-10).$trip;

		return ($namepart,$trip);
	}

	return clean_string($name) if $nonamedecoding;
	return (clean_string(decode_string($name,$charset)),"");
}

sub make_date($$;@)
{
	my ($time,$style,@locdays)=@_;
	my @days=qw(Sun Mon Tue Wed Thu Fri Sat);
	my @months=qw(Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec);
	@locdays=@days unless(@locdays);

	if($style eq "2ch")
	{
		my @ltime=localtime($time);

		return sprintf("%04d-%02d-%02d %02d:%02d",
		$ltime[5]+1900,$ltime[4]+1,$ltime[3],$ltime[2],$ltime[1]);
	}
	elsif($style eq "futaba" or $style eq "0")
	{
		my @ltime=localtime($time);

		return sprintf("%02d/%02d/%02d(%s)%02d:%02d",
		$ltime[5]-100,$ltime[4]+1,$ltime[3],$locdays[$ltime[6]],$ltime[2],$ltime[1]);
	}
	elsif($style eq "localtime")
	{
		return scalar(localtime($time));
	}
	elsif($style eq "tiny")
	{
		my @ltime=localtime($time);

		return sprintf("%02d/%02d %02d:%02d",
		$ltime[4]+1,$ltime[3],$ltime[2],$ltime[1]);
	}
	elsif($style eq "http")
	{
		my ($sec,$min,$hour,$mday,$mon,$year,$wday)=gmtime($time);
		return sprintf("%s, %02d %s %04d %02d:%02d:%02d GMT",
		$days[$wday],$mday,$months[$mon],$year+1900,$hour,$min,$sec);
	}
	elsif($style eq "cookie")
	{
		my ($sec,$min,$hour,$mday,$mon,$year,$wday)=gmtime($time);
		return sprintf("%s, %02d-%s-%04d %02d:%02d:%02d GMT",
		$days[$wday],$mday,$months[$mon],$year+1900,$hour,$min,$sec);
	}
	elsif($style eq "month")
	{
		my ($sec,$min,$hour,$mday,$mon,$year,$wday)=gmtime($time);
		return sprintf("%s %d",
		$months[$mon],$year+1900);
	}
	elsif($style eq "2ch-sep93")
	{
		my $sep93=timelocal(0,0,0,1,8,93);
		return make_date($time,"2ch") if($time<$sep93);

		my @ltime=localtime($time);

		return sprintf("%04d-%02d-%02d %02d:%02d",
		1993,9,int ($time-$sep93)/86400+1,$ltime[2],$ltime[1]);
	}
}

sub parse_http_date($)
{
	my ($date)=@_;
	my %months=(Jan=>0,Feb=>1,Mar=>2,Apr=>3,May=>4,Jun=>5,Jul=>6,Aug=>7,Sep=>8,Oct=>9,Nov=>10,Dec=>11);

	if($date=~/^[SMTWF][a-z][a-z], (\d\d) ([JFMASOND][a-z][a-z]) (\d\d\d\d) (\d\d):(\d\d):(\d\d) GMT$/)
	{ return eval { timegm($6,$5,$4,$1,$months{$2},$3-1900) } }

	return undef;
}

sub cfg_expand($%)
{
	my ($str,%grammar)=@_;
	$str=~s/%(\w+)%/
		my @expansions=@{$grammar{$1}};
		cfg_expand($expansions[rand @expansions],%grammar);
	/ge;
	return $str;
}

sub encode_base64($;$) # stolen from MIME::Base64::Perl
{
	my ($data,$eol)=@_;
	$eol="\n" unless(defined $eol);

	my $res=pack "u",$data;
	$res=~s/^.//mg; # remove length counts
	$res=~s/\n//g; # remove newlines
	$res=~tr|` -_|AA-Za-z0-9+/|; # translate to base64

	my $padding=(3-length($data)%3)%3; 	# fix padding at the end
	$res=~s/.{$padding}$/'='x$padding/e if($padding);

	$res=~s/(.{1,76})/$1$eol/g if(length $eol); # break encoded string into lines of no more than 76 characters each

	return $res;
}

sub decode_base64($) # stolen from MIME::Base64::Perl
{
	my ($str)=@_;

	$str=~tr|A-Za-z0-9+=/||cd;	# remove non-base64 characters
	$str=~s/=+$//; # remove padding
	$str=~tr|A-Za-z0-9+/| -_|; # translate to uuencode
	return "" unless(length $str);
	return unpack "u",join '',map { chr(32+length($_)*3/4).$_ } $str=~/(.{1,60})/gs;
}

sub dot_to_dec($)
{
	return unpack('N',pack('C4',split(/\./, $_[0]))); # wow, magic.
}

sub dec_to_dot($)
{
	return join('.',unpack('C4',pack('N',$_[0])));
}

sub mask_ip($$;$)
{
	my ($ip,$key,$algorithm)=@_;

	$ip=dot_to_dec($ip) if $ip=~/\./;

	my ($block,$stir)=setup_masking($key,$algorithm);
	my $mask=0x80000000;

	for(1..32)
	{
		my $bit=$ip&$mask?"1":"0";
		$block=$stir->($block);
		$ip^=$mask if(ord($block)&0x80);
		$block=$bit.$block;
		$mask>>=1;
	}

	return sprintf "%08x",$ip;
}

sub unmask_ip($$;$)
{
	my ($id,$key,$algorithm)=@_;

	$id=hex($id);

	my ($block,$stir)=setup_masking($key,$algorithm);
	my $mask=0x80000000;

	for(1..32)
	{
		$block=$stir->($block);
		$id^=$mask if(ord($block)&0x80);
		my $bit=$id&$mask?"1":"0";
		$block=$bit.$block;
		$mask>>=1;
	}

	return dec_to_dot($id);
}

sub setup_masking($$)
{
	my ($key,$algorithm)=@_;

	$algorithm=$has_md5?"md5":"rc6" unless $algorithm;

	my ($block,$stir);

	if($algorithm eq "md5")
	{
		return (md5($key),sub { md5(shift) })
	}
	else
	{
		setup_rc6($key);
		return (null_string(16),sub { encrypt_rc6(shift) })
	}
}

sub make_random_string($)
{
	my ($num)=@_;
	my $chars="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	my $str;

	$str.=substr $chars,rand length $chars,1 for(1..$num);

	return $str;
}

sub null_string($) { "\0"x(shift) }

sub make_key($$$)
{
	my ($key,$secret,$length)=@_;
	return rc4(null_string($length),$key.$secret);
}

sub hide_data($$$$;$)
{
	my ($data,$bytes,$key,$secret,$base64)=@_;

	my $crypt=rc4(null_string($bytes),make_key($key,$secret,32).$data);

	return encode_base64($crypt,"") if $base64;
	return $crypt;
}



#
# File utilities
#

sub read_array($)
{
	my ($file)=@_;

	if(ref $file eq "GLOB")
	{
		return map { s/\r?\n?$//; $_ } <$file>;
	}
	else
	{
		open FILE,$file or return ();
		binmode FILE;
		my @array=map { s/\r?\n?$//; $_ } <FILE>;
		close FILE;
		return @array;
	}
}

sub write_array($@)
{
	my ($file,@array)=@_;

	if(ref $file eq "GLOB")
	{
		print $file join "\n",@array;
	}
	else # super-paranoid atomic write
	{
		my $rndname1="__".make_random_string(12).".dat";
		my $rndname2="__".make_random_string(12).".dat";
		if(open FILE,">$rndname1")
		{
			binmode FILE;
			if(print FILE join "\n",@array)
			{
				close FILE;
				rename $file,$rndname2 if -e $file;
				if(rename $rndname1,$file)
				{
					unlink $rndname2 if -e $rndname2;
					return;
				}
			}
		}
		close FILE;
		die "Couldn't write to file \"$file\"";
	}
}



#
# Spam utilities
#

sub spam_check($$) # Deprecated function
{
	my ($text,$spamfile)=@_;
	return compile_spam_checker($spamfile)->($text);
}

sub compile_spam_checker(@)
{
	my @re=map {
		s{(\\?\\?&\\?#([0-9]+)\\?;|\\?&\\?#x([0-9a-f]+)\\?;)}{
			sprintf("\\x{%x}",($2 or hex $3));
		}gei if $has_encode;
		$_;
	} map {
		s/(^|\s+)#.*//; s/^\s+//; s/\s+$//; # strip perl-style comments and whitespace
		if(!length) { () } # nothing left, skip
		elsif(m!^/(.*)/$!) { $1 } # a regular expression
		elsif(m!^/(.*)/([xism]+)$!) { "(?$2)$1" } # a regular expression with xism modifiers
		else { quotemeta } # a normal string
	} map read_array($_),@_;

	return eval 'sub {
		$_=shift;
		# study; # causes a strange bug - moved to spam_engine()
		return '.(join "||",map "/$_/mo",(@re)).';
	}';
}

sub spam_engine(%)
{
	my %args=@_;
	my @spam_files=@{$args{spam_files}||[]};
	my @trap_fields=@{$args{trap_fields}||[]};
	my @included_fields=@{$args{included_fields}||[]};
	my %excluded_fields=map ($_=>1),@{$args{excluded_fields}||[]};
	my $query=$args{query}||new CGI;
	my $charset=$args{charset};

	for(@trap_fields) { spam_screen($query) if $query->param($_) }

	my $spam_checker=compile_spam_checker(@spam_files);
	my @fields=@included_fields?@included_fields:$query->param;
	@fields=grep !$excluded_fields{$_},@fields if %excluded_fields;
#	my $fulltext=join "\n",map decode_string($query->param($_),$charset),@fields;
	my $fulltext=join "\n",map $query->param($_),@fields;
	study $fulltext;

	spam_screen($query) if $spam_checker->($fulltext);
}

sub spam_screen($)
{
	my $query=shift;

	print "Content-Type: text/html\n\n";
	print "<html><body>";
	print "<h1>Anti-spam filters triggered.</h1>";
	print "<p>If you are not a spammer, you are probably accidentially ";
	print "trying to use an URL that is listed in the spam file. Try ";
	print "editing your post to remove it. Sorry for any inconvenience.</p>";
	print "<small style='color:white'><small>";
	print "$_<br>" for(map $query->param($_),$query->param);
	print "</small></small>";

	exit 0;
}


#
# Image utilities
#

sub analyze_image($$)
{
	my ($file,$name)=@_;
	my (@res);

	safety_check($file);

	return ("jpg",@res) if(@res=analyze_jpeg($file));
	return ("png",@res) if(@res=analyze_png($file));
	return ("gif",@res) if(@res=analyze_gif($file));

	# find file extension for unknown files
	my ($ext)=$name=~/\.([^\.]+)$/;
	return (lc($ext),0,0);
}

sub safety_check($file)
{
	my ($file)=@_;

	# Check for IE MIME sniffing XSS exploit - thanks, MS, totally appreciating this
	read $file,my $buffer,256;
	seek $file,0,0;
	die "Possible IE XSS exploit in file" if $buffer=~/<(?:body|head|html|img|plaintext|pre|script|table|title|a href|channel|scriptlet)/;
}

sub analyze_jpeg($)
{
	my ($file)=@_;
	my ($buffer);

	read($file,$buffer,2);

	if($buffer eq "\xff\xd8")
	{
		OUTER:
		for(;;)
		{
			for(;;)
			{
				last OUTER unless(read($file,$buffer,1));
				last if($buffer eq "\xff");
			}

			last unless(read($file,$buffer,3)==3);
			my ($mark,$size)=unpack("Cn",$buffer);
			last if($mark==0xda or $mark==0xd9);  # SOS/EOI
			die "Possible virus in image" if($size<2); # MS GDI+ JPEG exploit uses short chunks

			if($mark>=0xc0 and $mark<=0xc2) # SOF0..SOF2 - what the hell are the rest? 
			{
				last unless(read($file,$buffer,5)==5);
				my ($bits,$height,$width)=unpack("Cnn",$buffer);
				seek($file,0,0);

				return($width,$height);
			}

			seek($file,$size-2,1);
		}
	}

	seek($file,0,0);

	return ();
}

sub analyze_png($)
{
	my ($file)=@_;
	my ($bytes,$buffer);

	$bytes=read($file,$buffer,24);
	seek($file,0,0);
	return () unless($bytes==24);

	my ($magic1,$magic2,$length,$ihdr,$width,$height)=unpack("NNNNNN",$buffer);

	return () unless($magic1==0x89504e47 and $magic2==0x0d0a1a0a and $ihdr==0x49484452);

	return ($width,$height);
}

sub analyze_gif($)
{
	my ($file)=@_;
	my ($bytes,$buffer);

	$bytes=read($file,$buffer,10);
	seek($file,0,0);
	return () unless($bytes==10);

	my ($magic,$width,$height)=unpack("A6 vv",$buffer);

	return () unless($magic eq "GIF87a" or $magic eq "GIF89a");

	return ($width,$height);
}

sub make_thumbnail($$$$$;$)
{
	my ($filename,$thumbnail,$width,$height,$quality,$convert)=@_;

	# first try ImageMagick

	my $magickname=$filename;
	$magickname.="[0]" if($magickname=~/\.gif$/);

	$convert="convert" unless($convert);
	`$convert -background white -flatten -size ${width}x${height} -geometry ${width}x${height}! -quality $quality $magickname $thumbnail`;

	return 1 unless($?);

	# if that fails, try pnmtools instead

	if($filename=~/\.jpg$/)
	{
		`djpeg $filename | pnmscale -width $width -height $height | cjpeg -quality $quality > $thumbnail`;
		# could use -scale 1/n
		return 1 unless($?);
	}
	elsif($filename=~/\.png$/)
	{
		`pngtopnm $filename | pnmscale -width $width -height $height | cjpeg -quality $quality > $thumbnail`;
		return 1 unless($?);
	}
	elsif($filename=~/\.gif$/)
	{
		`giftopnm $filename | pnmscale -width $width -height $height | cjpeg -quality $quality > $thumbnail`;
		return 1 unless($?);
	}

	# try Mac OS X's sips

	`sips -z $height $width -s formatOptions normal -s format jpeg $filename --out $thumbnail >/dev/null`; # quality setting doesn't seem to work
	return 1 unless($?);

	# try PerlMagick (it sucks)

	eval 'use Image::Magick';
	unless($@)
	{
		my ($res,$magick);

		$magick=Image::Magick->new;

		$res=$magick->Read($magickname);
		return 0 if "$res";
		$res=$magick->Scale(width=>$width, height=>$height);
		#return 0 if "$res";
		$res=$magick->Write(filename=>$thumbnail, quality=>$quality);
		#return 0 if "$res";

		return 1;
	}

	# try GD lib (also sucks, and untested)
    eval 'use GD';
    unless($@)
    {
		my $src;
		if($filename=~/\.jpg$/i) { $src=GD::Image->newFromJpeg($filename) }
		elsif($filename=~/\.png$/i) { $src=GD::Image->newFromPng($filename) }
		elsif($filename=~/\.gif$/i)
		{
			if(defined &GD::Image->newFromGif) { $src=GD::Image->newFromGif($filename) }
			else
			{
				`gif2png $filename`; # gif2png taken from futallaby
				$filename=~s/\.gif/\.png/;
				$src=GD::Image->newFromPng($filename);
			}
		}
		else { return 0 }

		my ($img_w,$img_h)=$src->getBounds();
		my $thumb=GD::Image->new($width,$height);
		$thumb->copyResized($src,0,0,0,0,$width,$height,$img_w,$img_h);
		my $jpg=$thumb->jpeg($quality);
		open THUMBNAIL,">$thumbnail";
		binmode THUMBNAIL;
		print THUMBNAIL $jpg;
		close THUMBNAIL;
		return 1 unless($!);
	}

	return 0;
}


#
# Crypto code
#

sub rc4($$;$)
{
	my ($message,$key,$skip)=@_;
	my @s=0..255;
	my @k=unpack 'C*',$key;
	my @message=unpack 'C*',$message;
	my ($x,$y);
	$skip=256 unless(defined $skip);

	$y=0;
	for $x (0..255)
	{
		$y=($y+$s[$x]+$k[$x%@k])%256;
		@s[$x,$y]=@s[$y,$x];
	}

	$x=0; $y=0;
	for(1..$skip)
	{
		$x=($x+1)%256;
		$y=($y+$s[$x])%256;
		@s[$x,$y]=@s[$y,$x];
	}

	for(@message)
	{
		$x=($x+1)%256;
		$y=($y+$s[$x])%256;
		@s[$x,$y]=@s[$y,$x];
		$_^=$s[($s[$x]+$s[$y])%256];
	}

	return pack 'C*',@message;
}

my @S;

sub setup_rc6($)
{
	my ($key)=@_;

	$key.="\0"x(4-(length $key)&3); # pad key

	my @L=unpack "V*",$key;

	$S[0]=0xb7e15163;
	$S[$_]=add($S[$_-1],0x9e3779b9) for(1..43);

	my $v=@L>44 ? @L*3 : 132;
	my ($A,$B,$i,$j)=(0,0,0,0);

	for(1..$v)
	{
		$A=$S[$i]=rol(add($S[$i],$A,$B),3);
		$B=$L[$j]=rol(add($L[$j]+$A+$B),add($A+$B));
		$i=($i+1)%@S;
		$j=($j+1)%@L;	
	}
}

sub encrypt_rc6($)
{
	my ($block,)=@_;
	my ($A,$B,$C,$D)=unpack "V4",$block."\0"x16;

	$B=add($B,$S[0]);
	$D=add($D,$S[1]);

	for(my $i=1;$i<=20;$i++)
	{
		my $t=rol(mul($B,rol($B,1)|1),5);
		my $u=rol(mul($D,rol($D,1)|1),5);
		$A=add(rol($A^$t,$u),$S[2*$i]);
		$C=add(rol($C^$u,$t),$S[2*$i+1]);

		($A,$B,$C,$D)=($B,$C,$D,$A);
	}

	$A=add($A,$S[42]);
	$C=add($C,$S[43]);
		
	return pack "V4",$A,$B,$C,$D;
}

sub decrypt_rc6($)
{
	my ($block,)=@_;
	my ($A,$B,$C,$D)=unpack "V4",$block."\0"x16;

	$C=add($C,-$S[43]);
	$A=add($A,-$S[42]);

	for(my $i=20;$i>=1;$i--)
	{
		($A,$B,$C,$D)=($D,$A,$B,$C);
		my $u=rol(mul($D,add(rol($D,1)|1)),5);
		my $t=rol(mul($B,add(rol($B,1)|1)),5);
		$C=ror(add($C,-$S[2*$i+1]),$t)^$u;
		$A=ror(add($A,-$S[2*$i]),$u)^$t;

	}

	$D=add32($D,-$S[1]);
	$B=add32($B,-$S[0]);
		
	return pack "V4",$A,$B,$C,$D;
}

sub setup_xtea($)
{
}

sub encrypt_xtea($)
{
}

sub decrypt_xtea($)
{
}

sub add(@) { my ($sum,$term); while(defined ($term=shift)) { $sum+=$term } return $sum%4294967296 }
sub rol($$) { my ($x,$n); ( $x = shift ) << ( $n = 31 & shift ) | 2**$n - 1 & $x >> 32 - $n; }
sub ror($$) { rol(shift,32-(31&shift)); } # rorororor
sub mul($$) { my ($a,$b)=@_; return ( (($a>>16)*($b&65535)+($b>>16)*($a&65535))*65536+($a&65535)*($b&65535) )%4294967296 }

1;
