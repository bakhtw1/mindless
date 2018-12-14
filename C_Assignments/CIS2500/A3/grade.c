/*
*  Name: Waqas Bakht
*  Course: CIS*2500
*  Instructor: Stefan Kremer
*  Assignment 4
*/

#include "aim.h"

int main( int argc, char *argv[] )
{

    if(argc != 2)
    {
        fprintf(stderr, "Usage: <filename.txt>");
        exit(0);
    }
    else
    {
        strtok(argv[1], "\n");
    }

    grade(argv[1]);
    
    return 0;
}
