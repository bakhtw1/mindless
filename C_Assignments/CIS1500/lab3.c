#include <stdio.h>
#include <string.h>
#define SIZE 30


int main(void){

    char word[SIZE] = "";
    int  multiplier[SIZE];
    int i = 0;
    int j = 0;
    int k = 0;
    int wordLen = 0;
    char space = ' ';

    printf("Enter a word:\n");
    scanf("%s", word);

    wordLen = strlen(word);

    printf("Enter %d integers:\n", wordLen);

    for(i = 0; i < wordLen; i++){
        scanf("%d", &multiplier[i]);
        if(multiplier[i] < 0)
        {
          printf("Please enter a positive integer:\n");
          scanf("%d", &multiplier[i]);
        }
    }

    printf("Streched string = ");
    for(j = 0; j < wordLen; j++)
    {
       while(k < (multiplier[j]))
       {
            printf("%c", word[j]);
            k++;
       }
       k = 0;
    }
    printf("\n");

    return 0;
}
