#!/usr/bin/perl

use strict;
use warnings;
use version; our $version = qv('5.16.0');
use Text::CSV 1.32;

#  Author: Waqas Bakht
#  File: popDens.pl
#  Final Project (Milestone III)
#  Team: Delhi
#
#  Subject: 
#  
#  	The purpose of this program is to take in the population census file and fetch
#  the contents that will be useful for what we need to answer the first question. The output will be 
#  a .csv file that only contains the Province, Province Division, and Pop density per square 
#  kilomtre based on the division.

# Required Delimitres and variables and arrays.

my $EMPTY = q{};
my $DLIM = q{,};
my $SPACE = q{ };
my $filename;
my $outfile;
my @densities;

my $csv = Text::CSV->new({ sep_char => $DLIM });

# Argument Fetch
if ($#ARGV != 0)
{
    print "Usage: *.pl <populationCensus.txt>\n" or die "Print Failiure\n";
    exit;
}
else
{
    $filename = $ARGV[0];
}

# Open census file 
open my $popdens, '<', $filename or die "Unable to open $filename\n";
@densities = <$popdens>;
close $popdens or die "Unable to close $filename\n";

# Output filename is decided for you
$outfile = ">" . "popDensities.CSV";
open FILE, $outfile or die $!;

# Header for file
print FILE "Province, Division, Population Density Per Square Kilometre\n";

# Loop through file contents and select the worthy items
foreach my $i ( @densities )
{

    if($csv->parse($i))
    {
        my @masterfields = $csv->fields();
        if( defined($masterfields[5]) 
            and $masterfields[5] eq "Population density per square kilometre")
        {
      	     print FILE "\"".$masterfields[1]."\"".$DLIM."\"".$masterfields[2]."\"".$DLIM."\"".$masterfields[7]."\"\n" 
             or die "Unable to print, Check lines 29-42";  
        }
    }

}
close FILE;






