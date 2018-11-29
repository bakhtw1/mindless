#include <stdio.h>
#include <string.h>

//Waqas Bakht - 0981571
//wbakht@uoguelph.ca
//Assignment 2 Question 5
//Ritu C
//CIS 1500
//October 31, 2017

int main(void)
{
    //declare necessary variables
    int userChoice = 0;
    int product    = 0;
    int i,k;

    //one 2D array for the multiplication table
    int multTable[9][9];
    //one 2D array for the string headers
    char numbs[9][6];
    //start it off with a yes
    char cont = 'y';

    strcpy(numbs[0], "One  ");
    strcpy(numbs[1], "Two  ");
    strcpy(numbs[2], "Three");
    strcpy(numbs[3], "Four ");
    strcpy(numbs[4], "Five ");
    strcpy(numbs[5], "Six  ");
    strcpy(numbs[6], "Seven");
    strcpy(numbs[7], "Eight");
    strcpy(numbs[8], "Nine ");

    //assign correct values to multiplication table
    for(i = 0; i < 9; i++)
    {
        for(k = 0; k < 9; k++)
        {
            multTable[i][k] = (i+1) * (k+1);
        }
    }

    //the program keeps running until user gets tired of math
    while ( cont == 'y')
    {
        printf("Enter zero (0) to see all mutiplication tables from 1 - 9 OR\n");
        printf("Enter a specific number between 1 and 9 to see its multiplication table\n");

        printf("Enter a choice: ");
        scanf("%d", &userChoice);

        //spacing is important in this part to make the table easily readable
        //which is why the strings declared above all have the same amount of characters
        if ( userChoice == 0 )
        {
            printf("\t\t\tPrinting Mulitplication Tables 1 - 9\n\n");
            for(int g = 0; g < 80; g++) printf("*"); printf("\n");
            //a series of loops print the correct numbers and amount of spaces inbetween
            printf("        ");
            for(i = 0; i < 9; i++) printf("%s   ", numbs[i]);
            printf("\n\n");
            for(i = 0; i < 9; i++)
            {
                printf("%s", numbs[i]);
                for(k = 0; k < 9; k++)
                {
                    printf("   %d", multTable[i][k]);
                    //these single purpose if statements are made so spacing doesnt become an issue with double digit numbers
                    if ((i+1)*(k+1) >= 10) printf("   ");
                    if ((i+1)*(k+1) < 10) printf("    ");
                }
                printf("\n");
            }
            for(int g = 0; g < 80; g++) printf("*"); printf("\n");
        }
        //this program should work with almost any reasonable number, but has been restricted between 1 and 9 (inclusive)
        else if ( userChoice > 9 || userChoice < 0)
        {
            printf("Invalid number. Please enter a number inbetween 1 and 9(inclusive)\n");
        }
        //print the multiplication table for the specific number inputted
        else
        {
            printf("Printing multipliction table for %d:\n", userChoice);
            printf("-----------------------------------\n");
            for(i = 0; i < 9; i++)
            {
                product = userChoice * (i+1);
                printf("%d X %d = %d\n", userChoice, i+1, product);
            }
        }
        //user is given the choice of repeating the program or exiting
        printf("Do you wish to continue? Enter y for yes, any other charecter for no: ");
        scanf(" %c", &cont);
    }

    return 0;

}
