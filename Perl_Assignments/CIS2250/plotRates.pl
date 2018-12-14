#!/usr/bin/perl

use strict;
use warnings;
use version;	our $VERSION = qv('5.16.0');

use Statistics::R;
#use Data::Printer;

#  Author: Waqas Bakht
#  Team: Delhi
#  Subject: 
#  Plotter for the outputs for questions 1 and 2
#  Plots 2 bargraphs on the same page

my $infilename1;
my $infilename2;
my $pdffilename;
my @plottitle;
my @yaxis;
my @xaxis;

print "Enter input file name for the labour data set (.txt):\n";
$infilename1 = <>;
chomp($infilename1);

print "Enter the plot title: ";
$plottitle[0] = <>;
chomp($plottitle[0]);

print "Enter the x-axis label: ";
$xaxis[0] = <>;
chomp($xaxis[0]);

print "Enter y-axis label: ";
$yaxis[0] = <>;
chomp($yaxis[0]);

print "Enter input file name for the population densities (.txt):\n";
$infilename2 = <>;
chomp($infilename2);

$plottitle[1] = "Average Population Density For Each Province Based On Its Counties (2011)";

$xaxis[1] = "Province";
 
$yaxis[1] = "Population Density (Per Square Kilometre)";

print "Enter output file name (.pdf)\n";
$pdffilename = <>;
chomp($pdffilename);

print "input file = $infilename1, $infilename2\n";
print "pdf file = $pdffilename\n";

my $R = Statistics::R->new();

$R->run(qq`pdf("$pdffilename" , paper="letter")`);
$R->run(q`library(ggplot2)`);
$R->run(q`library(gridExtra)`);
$R->run(qq`data <- read.csv("$infilename1")`);
$R->run(qq`data2 <- read.csv("$infilename2")`);
$R->run(qq`plottitle1 <- "$plottitle[0]"`);
$R->run(qq`plottitle2 <- "$plottitle[1]"`);
$R->run(qq`xlab1 <- "$xaxis[0]"`);
$R->run(qq`xlab2 <- "$xaxis[1]"`);
$R->run(qq`ylab1 <- "$yaxis[0]"`);
$R->run(qq`ylab2 <- "$yaxis[1]"`);

print "Drawing graphs...\n";

$R->run
(q`p1 <- ggplot(data, aes(x=Location, y=Total)) + geom_bar(stat = "identity", fill="blue") + ggtitle(plottitle1) + ylab(ylab1) + xlab(xlab1) + theme(axis.text.x = element_text(angle = 90, hjust = 1))`);

$R->run(q`p2 <- ggplot(data2, aes(x=Location, y=Total)) + geom_bar(stat = "identity", fill="steelblue") + ggtitle(plottitle2) + ylab(ylab2) + xlab(xlab2) + theme(axis.text.x = element_text(angle = 90, hjust = 1))`);

$R->run(q`grid.arrange(p1, p2, nrow=2)`);

$R->run(q`dev.off()`);

$R->stop();

print "Complete\n";

