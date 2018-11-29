#include <stdio.h>
#include <string.h>

int main(void)
{

    int numLines  = 0;
    int numSpaces = 0;

    printf("Number of lines? ");
    scanf("%d", &numLines);

    printf("Number of spaces? ");
    scanf("%d", &numSpaces);

    char starArr[numLines][numLines + numSpaces];

    for(int i = 0; i < numLines; i++)
    {
        for(int j = 0; j < (numLines + numSpaces); j++)
        {
             starArr[i][j] = ' ';

             if(j < (numLines/2) || j >= (numLines/2) + numSpaces)
             {
                 starArr[i][j] = '*';
             }
             if( ( i <  (numLines/2) - 1 || i > numLines/2 ) && ( j < (numLines/2) - 1 || j > (numLines/2 + numSpaces) ) )
             {
                 starArr[i][j] = ' ';
             }
        }
    }

    for(int k = 0; k < numLines; k++){
        for(int l = 0; l < (numLines + numSpaces); l++)
        {
           printf("%c", starArr[k][l]);
        }
        printf("\n");
    }

}
