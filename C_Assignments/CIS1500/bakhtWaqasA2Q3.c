#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Waqas Bakht - 0981571
//wbakht@uoguelph.ca
//Assignment 2 Question 3
//Ritu C
//CIS 1500
//October 31, 2017

int main (void)
{

     char sentence[50] = "";

     int vowelCount     = 0;
     int consonantCount = 0;
     int j              = 0;
     int totalChar      = 0;

     double  wordLen    = 1.0;
     double numWord     = 1.0;
     double avgWordLen  = 0.0;

     printf("\n");
     printf("Enter a sentence: ");

     fgets(sentence, 50, stdin);
     sentence[strlen(sentence) - 1] = '\0';

     wordLen = strlen(sentence);

     while(j < strlen(sentence))
     {
         if ( ( isalpha(sentence[j]) || ispunct(sentence[j]) ) && isspace(sentence[j+1])  )
         {
             numWord++;
         }
         if ( !isalpha(sentence[j]) )
         {
             sentence[j] = ' ';
             totalChar--;
         }

         switch (sentence[j]) {
             case 'a': case 'e': case 'i': case 'o': case 'u':
             case 'A': case 'E': case 'I': case 'O': case 'U':
                vowelCount++;
                break;
             case ' ':
                break;
             default:
                consonantCount++;
                break;
         }
         j++;
     }

     wordLen = wordLen + totalChar;
     avgWordLen = wordLen/numWord;


     printf("Number of vowels in the sentence = %d\n", vowelCount);
     printf("Number of consonants in the sentence = %d\n", consonantCount);
     printf("Average word length: %0.1lf\n", avgWordLen);
     printf("\n");

     return 0;
}
