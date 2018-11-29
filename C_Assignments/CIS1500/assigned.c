#include <stdio.h>

int main (void)
{
    int spaces = 0, rows = 0, blanks = 1;
    int i, j, k, l;

    printf("Enter the number of lines: ");
    scanf("%d", &rows);
    
    //prompts the user to enter an even number if they enter an odd one
    while(rows % 2 != 0)
    {
        printf("Try entering an even number: ");
        scanf("%d", &rows);
    }

    printf("Enter the width between left and right figure: ");
    scanf("%d", &spaces);

    //by getting the number of rows we can determine a pattern in the diamond

    //prints the first half of the diamond
    //the number of blankspaces in the first line is equal to half the number of total lines minus 1
    blanks = (rows/2) - 1;

    //first for loop prints the necessary  number of rows
    for(i = 0; i <= rows/2; i++)
    {
        //the number of spaces in each line decreases by one as you print each new line
        for(j = 0; j <= blanks; j++)
            printf(" ");

        blanks--;

        //the number of stars is equal to the row number  minus one 
        for(k = 0; k <= 2*i-1; k++)
        {
            printf("*");
            //if we have printed half the stars on one line and we are on the last row start printing the specified number of "-"
            if( (k >= i-1 && k <= i-1) && i == rows/2 )
            {
               for(l = 0; l < spaces; l++)
                 printf("-");
            }
            //if we have printed half the stars on one line  and we are anywhere but the last row print out the specified number of " "
            else if( k >= i-1 && k <= i-1  )
            {
               for(l = 0; l < spaces; l++)
                 printf(" ");
            }
        }
        printf("\n");
    }

    //prints the second half of the diamond
    //the number of intial spaces is zero because this half is flipped 
    blanks = 0;

    
    for(i = 0; i < rows/2 ; i++)
    {
        for(j = 0; j < blanks; j++)
            printf(" ");

        blanks++;

        for(k = 0; k < 2*((rows/2)-i); k++)
        {
             printf("*");
             if( (k >= ((rows/2)-i)-1 && k <= ((rows/2)-i)-1) && i == 0 )
             {
                 for(l = 0; l < spaces; l++)
                     printf("-");
             }
             else if( k >= ((rows/2)-i)-1 && k <= ((rows/2)-i)-1 )
             {
               for(l = 0; l < spaces; l++)
                   printf(" ");
             }
        }
        printf("\n");
    }

      return 0;
}
