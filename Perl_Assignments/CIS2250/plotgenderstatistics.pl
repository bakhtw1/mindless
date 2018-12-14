#!/usr/bin/perl

use strict;
use warnings;
use version;	our $VERSION = qv('5.16.0');

use Statistics::R;

#  Author: Waqas Bakht
#  Team: Delhi
#  
#
#
#
#
#

my $infilename1;
my $infilename2;
my $pdffilename;
my @plottitle;
my @yaxis;
my @xaxis;


print "Enter input file name for the male labour data set (.txt): ";
$infilename1 = <>;
chomp($infilename1);

$plottitle[0] = "Employment Rates for Males for the Last 10 Years";

$xaxis[0] = "Year";

$yaxis[0] = "Percentage";

print "Enter input file name for the female labour data set (.txt): ";
$infilename2 = <>;
chomp($infilename2);

$plottitle[1] = "Employment Rate for Females for the Last 10 Years";
 
$xaxis[1] = "Year";
 
$yaxis[1] = "Percentage";

print "Enter output file name (.pdf)\n";
$pdffilename = <>;
chomp($pdffilename);

print "input file = $infilename1\n";
print "pdf file = $pdffilename\n";

print "Drawing graphs...\n";

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

$R->run
(q`p1 <- ggplot(data, aes(x=Year, y=Total)) + geom_line() + geom_point(size=2) + ggtitle(plottitle1) + ylab(ylab1) + xlab(xlab1) + scale_y_continuous(limits=c(60,90)) + scale_x_continuous(limits=c(2008,2018))`);
$R->run(q`p2 <- ggplot(data2, aes(x=Year, y=Total)) + geom_line() + geom_point(size=2) + ggtitle(plottitle2) + ylab(ylab2) + xlab(xlab2) + scale_y_continuous(limits=c(60,90)) + scale_x_continuous(limits=c(2008,2018))`);

$R->run(q`grid.arrange(p1, p2, nrow=2)`);

$R->run(q`dev.off()`);

print "Complete\n";

$R->stop();

