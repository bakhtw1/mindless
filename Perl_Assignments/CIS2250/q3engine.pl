#!/usr/bin/perl

use strict;
use warnings;
use version; our $version = qv('5.16.0');
use Text::CSV 1.32;

#  Author: Waqas Bakht
#  File q3engine.pl
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
my @geographies;
my @averages;
my @densitygeos;
my $count = 0;
my $counter = 0;
my $total = 0;

my $csv = Text::CSV->new({ sep_char => $COMMA });

print "Enter the .csv filename for population of high school graduates preprocessed from data file:\n";
$in_filename = <>;
chomp($in_filename);

print "Enter an name for the output file with the file extention .txt:\n";
$outfile_name = <>;
chomp($outfile_name);

open my $rates, '<', $in_filename or die "Unable to opne $in_filename\n";
@popvalues = <$rates>;
close $rates or die "Unable to close $in_filename\n";

print "Writing to".$SPACE.$outfile_name."\n";
my $out = '>'.$outfile_name;
open FILE, $out or die $!;

print FILE "Location,Total\n";
foreach my $i (@popvalues)
{
    if($csv->parse($i))
    {
        my @masterfields = $csv->fields();
        #print "master:".$SPACE.$masterfields[2]."\n"; 
        if( $masterfields[3] eq "15 years and over"
            and $masterfields[2] eq "Both sexes" 
	    and $masterfields[1] ne "Canada" )
        {
            $geographies[$count] = $masterfields[1];
            if($masterfields[1] ne $geographies[$count - 1])
            {
                #print "Total:".$SPACE.$total."\n";
                $averages[$counter] = $total/12;
                $total = 0;
		print FILE $geographies[$count - 1].$COMMA.$averages[$counter]."\n";
                $counter++;
            }
	    $total = $total + $masterfields[4];
            $count++;
        }
    }
}

close FILE;


