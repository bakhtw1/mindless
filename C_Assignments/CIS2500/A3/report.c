/*
*  Name: Waqas Bakht
*  Course: CIS*2500
*  Instructor: Stefan Kremer
*  Assignment 4
*/

#include "aim.h"

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        fprintf(stderr, "Usage: <student_id> <term>\n");
        exit(0);
    }
    else
    {
        strtok(argv[2], "\n");
        report(atoi( argv[1]), argv[2] );
    }
    
    return 0;
}
