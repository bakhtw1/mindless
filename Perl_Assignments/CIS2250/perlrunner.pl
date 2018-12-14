#!/usr/bin/perl

use strict;
use warnings;
use version; our $version = qv('5.16.0');
use Term::ANSIColor;

my $switch;

print color('reset');

print "\n\t";

print color('underline'); 
print color('red');
print "Welcome to the Team Delhi Query Engine, A series of programs designed to only answer specific questions.\n\n";

print color('reset');
print color('blue');

print "\tQuestion 1: Does a Higher Population Density stimulate a higher number of educated people?\n";
print "\tQuestion 2: Does a Higher Population Density stimulate a higher employment rate??\n";
print "\tQuestion 3: Do provinces with a higher amount of universites have a higher number of educated \n";
print "\tQuestion 4: Is there a correlation between teh number of educated people and the total population?\n";
print "\tQuestion 5: How does the employment rate compare for men and women for the last decade?\n\n";

print color('reset');

print "Pick a question [1/2/3/4/5]: ";
$switch = <>;

if($switch == 1)
{
    question1();
}
elsif($switch == 2)
{
    question2();
}
elsif($switch == 3)
{
    question3();
}
elsif($switch == 4)
{
    question4();
}
elsif($switch == 5)
{
    question5();
}
else
{
    print "Invalid, run again\n";
}

print color('reset');

sub question1
{
    print color('blue');
    print "File prompts: <education_rates.csv> <popDensities.CSV>\n";
    system('perl', "q1q2engine.pl")==0 or die "failed to execute";
    system('perl', "plotRates.pl")==0 or die "failed to execute";
}

sub question2
{
    print color('green');
    print "File prompts <emplymentrates.csv> <popDensities.CSV>\n";
    system('perl', "q1q2engine.pl")==0 or die "failed to execute";
    system('perl', "plotRates.pl")==0 or die "failed to execute";
}

sub question3
{
    print color('bright_blue');
    system('perl', "q3engine.pl"); 
    system('perl', "ploteduanduni.pl");
}

sub question4
{
    print color('magenta');
    system('perl', "q4p1.pl", "popTotals.CSV", "highschool_grad_totals_2011.csv")==0 or die "failed to execute\n";
    system('perl', "ploteducationvscensus.pl", "censusVsEducation.txt", "output4.pdf")==0 or die "failed to execute\n";
}

sub question5
{
    print color('cyan');
    print "File prompts <emplymentratesbygender.csv>\n";
    print "Males\n";
    system('perl', "q5p1.pl")==0 or die "failed to execute";
    print "Females\n";
    system('perl', "q5p1.pl")==0 or die "failed to execute";
    system('perl', "plotgenderstatistics.pl")==0 or die "failed to execute";
}


