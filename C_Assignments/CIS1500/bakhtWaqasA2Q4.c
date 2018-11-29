#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Waqas Bakht - 0981571
//wbakht@uoguelph.ca
//Assignment 2 Question 4
//Ritu C
//CIS 1500
//October 31, 2017

int main(void)
{

    printf("\n");

    char goodStr[50] = "";
    int c = 0;
    int goodness = 0;

    printf("Enter a string with no spaces: ");
    scanf("%s", goodStr);

    //as the loop cycles through each charecter
    for(c = 0; c < strlen(goodStr); c++)
    {
        //if the string contains anything besides a number then the goodness
        //is equal to 0 and the loop ends resulting in 0 goodness :(
        if( isalpha(goodStr[c]) || ispunct(goodStr[c]) )
        {
            goodness = 0;
            break;
        }
        //for any 1 in the string the goodness increases by one
        if( goodStr[c] == '1' )
        {
             goodness++;
        }
    }

    printf("Goodness of the input string is %d\n", goodness);

    return 0; 

}
