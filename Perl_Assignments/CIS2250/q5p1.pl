#!/usr/bin/perl

use strict;
use warnings;
use version; our $version = qv('5.16.0');
use Text::CSV 1.32;

#  Author: Waqas Bakht
#  File q1p1.pl
#  Final Project Milestone
#  Team Delhi
#
#  Subject:
#  
#  Now that the data has been preprocessed into what we need, 
#  we can move forward with the new data and answew the question 
#  that we desire.

# Required variable declarations
my $EMPTY = q{};
my $SPACE = q{ };
my $COMMA = q{,};
my $in_filename;
my $outfile_name;
my @popvalues;
my @densities;
my $ave;
my @year;
my $count = 0;
my $counter = 0;
my $total = 0;
my @stringsplit;
my $gender;
my $k;
my $switch;

my $csv = Text::CSV->new({ sep_char => $COMMA });

print "Enter the .csv filename for population of high school graduates preprocessed from data file:\n";
$in_filename = <>;
chomp($in_filename);

print "Enter for males or enter for females [M/F]\n";
$switch = <>;
chomp($switch);
if($switch eq "M")
{
    $gender = "Males";
}
elsif($switch eq "F")
{
    $gender = "Females";
}
else
{
    print "Non value try again\n";
    exit;
}

print "Enter an name for the output file with the file extention .txt:\n";
$outfile_name = <>;
chomp($outfile_name);

    open my $rates, '<', $in_filename or die "Unable to opne $in_filename\n";
    @popvalues = <$rates>;
    close $rates or die "Unable to close $in_filename\n";

    print "Writing to".$SPACE.$outfile_name."\n";
    my $out = '>'.$gender.$outfile_name;
    open FILE, $out or die $!;

    print FILE "Year,Total\n";
    foreach my $i (@popvalues)
    {
        if($csv->parse($i))
        {
            my @masterfields = $csv->fields();
            #print "master:".$SPACE.$masterfields[2]."\n"; 
            if( $masterfields[3] eq "15 years and over"
                and $masterfields[2] eq $gender 
	        and $masterfields[1] eq "Canada" )
            {
	        @stringsplit = split(/\//, $masterfields[0]);
		$year[$count] = $stringsplit[0];
	        if( $year[$count - 1] ne $stringsplit[0] 
		    or ($stringsplit[0] eq "2018" and $stringsplit[1] eq "02") )
	        {
		    print FILE $year[$count - 1].$COMMA.$masterfields[4]."\n";
	        }
		$count++;
            }
        }
    }

    close FILE;














