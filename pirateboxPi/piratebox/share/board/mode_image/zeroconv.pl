#!perl

use CGI::Carp qw(fatalsToBrowser);

use strict;

use Data::Dumper;

print "Content-Type: text/plain\n\n";

my @bump=read_array("bump.txt");
my @threads=glob("res/*.html");
my %bumporder;

for(0..$#bump) { $bumporder{$bump[$_]}=$_; }

foreach my $thread (@threads)
{
	my %meta;
	my @page=read_array($thread);
	my ($num)=$thread=~m!/([0-9]+)!;
	my ($title)=$page[1]=~m!<span class="filetitle">\s*(.*?)\s*</span>!;
	my ($author)=$page[1]=~m!<span class="postername">\s*(.*?)\s*</span>!;
	my ($trip)=$page[1]=~m!<span class="postertrip">\s*(.*?)\s*</span>!;

	$meta{lasthit}=$bumporder{$num};
	$meta{postcount}=@page-2;
	$meta{permasage}=0;
	$meta{title}=$title;
	$meta{author}=$author.$trip;

	$page[0]=~s{\s*<html>}{<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"><html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">};
	$page[0]=~s!(<input[^>]*[^/])>!$1/>!;
	$page[$#page]=~s!(<input[^>]*[^/])>!$1/>!;
	$page[$#page]=~s!</form>(\s*<div class="footer")!$1!;

	for(1..$#page-1)
	{
		$page[$_]=~s!(<img[^>]*[^/])>!$1/>!;
	}

	print "$thread: $meta{postcount} posts, \"$meta{title}\" by $meta{author}, bumporder $meta{lasthit}\n";

	unshift @page,make_meta_header(%meta);
	write_array("_$thread",@page);
}

print "\n\n=== Done ===";





sub make_meta_header(%)
{
	my (%meta)=@_;
	$Data::Dumper::Terse=1;
	$Data::Dumper::Indent=0;
	return '<!-- '.Dumper(\%meta).' -->';
}

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
	else
	{
		open FILE,">$file" or die "Couldn't write to directory";
		print FILE join "\n",@array;
		close FILE;
	}
}
