#!/usr/bin/perl

use strict;
use warnings;
use version; our $version = qv('5.16.0');
use Text::CSV 1.32;

#  Author: Waqas Bakht, Jacob Wieler
#  File: q4p1.pl
#  Final Project (Milestone III)
#  Team: Delhi
#
#  Subject: 
#  
#  	The purpose of this program is to take in two files, one with census population data, and one with data representing the educated population.
#       This program will take the data and output, to a text file, the total population and the total educated popualation.

# Required Delimitres and variables and arrays.

my $EMPTY = q{};
my $DLIM = q{,};
my $SPACE = q{ };
my $filename;
my $filename2;
my $outfile;
my @populations;
my @labourStats;
my $totalPop = 0;
my $totalEducatedPop = 0;

my $csv = Text::CSV->new({ sep_char => $DLIM });

# Argument Fetch
if ($#ARGV != 1)
{
    print "Usage: *.pl <populationCensus.txt> <labourStats.txt>\n" or die "Print Failiure\n";
    exit;
}
else
{
    $filename = $ARGV[0];
    $filename2 = $ARGV[1];
}

# Open census file 
open my $popTotals, '<', $filename or die "Unable to open $filename\n";
@populations = <$popTotals>;
close $popTotals or die "Unable to close $filename\n";

open my $labourFile, '<', $filename2 or die "Unable to open $filename2\n";
@labourStats = <$labourFile>;
close $labourFile or die "Unable to close $filename2\n";

# Output filename is decided for you
$outfile = ">"."censusVsEducation.txt";
open FILE, $outfile or die $!;

# Header for file
print FILE "Characteristic,Value\n";

# Loop through file contents and select the worthy items
foreach my $i ( @populations )
{

    if($csv->parse($i))
    {
	my @masterfields = $csv-> fields();
        if( defined($masterfields[2]) 
            and $masterfields[2] ne " Population Total")
        {
	   $totalPop += int($masterfields[2]);
        }
    }

}

foreach my $i ( @labourStats )
{
    if($csv->parse($i))
    {
        my @masterfields2 = $csv-> fields();
        if(defined($masterfields2[1])
           and $masterfields2[1] ne "Value")
	{
	    $totalEducatedPop += int($masterfields2[1]) * 1000;
	}
    }
}

$totalEducatedPop /= 12;

print FILE "EducatedPopulation".$DLIM.$totalEducatedPop."\n"."TotalPopulation".$DLIM.$totalPop."\n";
#print FILE "Canada".$DLIM.$totalEducatedPop.$DLIM.$totalPop."\n";
close FILE;






