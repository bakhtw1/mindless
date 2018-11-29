#include <stdio.h>
#include <math.h>

//Waqas Bakht - 0981571
//wbakht@uoguelph.ca
//Assignment 2 Question 2
//Ritu C
//CIS 1500
//October 31, 2017

int main (void)
{


    double populations[10];
    double maxPop = 0.0;
    double minPop = 0.0;
    double avgPop = 0.0;
    double totPop = 0.0;

    int highest = 0, lowest = 0;

    printf("Enter the populations of 10 provinces of Canada (in millions):\n");

    for(int i = 0; i < 10; i++)
    {
        printf("Pronvince number %d: ", i + 1);
        scanf("%lf", &populations[i]);

    }

    printf("\n");

    maxPop = populations[0];
    minPop = populations[0];
    for(int k = 0; k < 10; k++)
    {
        if(populations[k] > maxPop)
        {
            maxPop = populations[k];
            highest = k + 1;
        }
        if(populations[k] < minPop)
        {
            minPop = populations[k];
            lowest = k + 1;
        }
        totPop = totPop + populations[k];
    }

    avgPop = totPop / 10.0;

    printf("********************************************************************\n");
    printf("Average Population in Canada = %0.1lf million\n", avgPop);
    printf("Province number %d has the highest population\n", highest);
    printf("Highest population =  %0.1lf million\n", maxPop);
    printf("Province number %d has the lowest population\n", lowest);
    printf("Lowest population = %0.1lf million\n", minPop);
    printf("********************************************************************\n");



}
