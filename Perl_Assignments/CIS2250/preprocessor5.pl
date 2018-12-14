#!/usr/bin/perl

use strict;
use warnings;
use version; our $version = qv('5.16.0');
use Math::Round qw(:all);
use Text::CSV 1.32;

#  Author: Waqas Bakht
#  File: labstats.pl
#  Final Project (Milestone III)
#  Team: Delhi
#
#  Subject: 
#  
#  The purpose of this file is to fetch all the total population for anyone that has a high school education.
#  The output will be a file "education_rates.csv" and it will contain all the populations of people that have
#  a high school education in the year 2011.
 
# Required Delimitres and variables and arrays.
my $EMPTY = q{};
my $SPACE = q{ };
my $COMMA = q{,};
my $SLASH = q{/};
my $outfile;
my $outfile_name = "emplymentratesbygender.csv";
my $filename;
my @statistics;
my $percentage;
my $count = 0;

my $csv_COM = Text::CSV->new({ sep_char => $COMMA });

if ($#ARGV != 0)
{
    print "Usage: <labourstatsfile.csv>\n" or die "Print Fail\n";
    exit;
}
else
{
    $filename = $ARGV[0];
}

# Read in file data
open my $edurates, '<', $filename or die "Unable to open $filename\n";
@statistics = <$edurates>;
close $edurates or die "Unable to close $filename\n";

# output file name is decided for you
$outfile = ">".$outfile_name;
open FILE, $outfile or die $!;

# Header for the file
print FILE "Year,Location,Gender,Age,Value\n";

print "Processing file... May take a while, exit using control+c to exit\n";

# Loop the the large labour stats file
foreach my $i (@statistics)
{
    if($csv_COM->parse($i))
    {
        my @masterfields = $csv_COM->fields();
  
        # Using a regular expression to find that the date field contains the year 2011
        if( $masterfields[0] =~ m/20(0[8-9]|1[0-8])/
            and $masterfields[2] eq "Employment rate (percentage)" 
            and $masterfields[3] eq "University degree" 
	    and ($masterfields[4] eq "Females" or $masterfields[4] eq "Males") )
        {
	    print FILE $masterfields[0].$COMMA.$masterfields[1].$COMMA.$masterfields[4].
            $COMMA.$masterfields[5].$COMMA.$masterfields[8]."\n";
        }
    }
    # Tells you completion percentage of the output file, 
    if ($count % 100000 == 0)
    {
        $percentage = sprintf("%.2f",($count/$#statistics)*100);
        print "Percentage Complete: ".$SPACE.$percentage."\n";
    }
    $count++;
}
print "Complete\n";
close FILE;

