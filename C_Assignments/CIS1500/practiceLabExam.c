#include <stdio.h>
#include <string.h>
#include <ctype.h>

void monthToNumber(char month[], int * numMonth);
void printDateInChangedFormat(int month, int day, int year);

struct Dates{

    int day;
    char wordMonth[10];
    int nuMonth;
    int year;

};

//sample input: December 1 2017

int main(void){

    struct Dates currentDate;

    printf("Please enter the current date in this format: Month Day Year\n");
    scanf("%s%d%d", currentDate.wordMonth, &currentDate.day, &currentDate.year);

    monthToNumber(currentDate.wordMonth, &currentDate.nuMonth);
    printDateInChangedFormat(currentDate.nuMonth, currentDate.day, currentDate.year);

}

void printDateInChangedFormat(int month, int day, int year){

    printf("%02d/%02d/%4d\n", month, day, year);

}

void monthToNumber(char month[], int * numMonth){

    char months[12][10];

    strcpy(months[0], "january");
    strcpy(months[1], "febuary");
    strcpy(months[2], "march");
    strcpy(months[3], "april");
    strcpy(months[4], "may");
    strcpy(months[5], "june");
    strcpy(months[6], "july");
    strcpy(months[7], "august");
    strcpy(months[8], "september");
    strcpy(months[9], "october");
    strcpy(months[10], "november");
    strcpy(months[11], "december");

    for(int i = 0; month[i] != '\0'; i++){
        month[i] =  tolower(month[i]);
    }

    for(int i = 0; i < 12; i++){
         if(strcmp(month, months[i]) == 0){
             *numMonth = i + 1;
         }
    }


}



