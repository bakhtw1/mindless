/*
*  Name: Waqas Bakht
*  Course: CIS*2500
*  Instructor: Stefan Kremer
*  Assignment 4
*/

#include "aim.h"

int main( int argc, char *argv[] )
{

    if(argc != 4)
    {
        fprintf(stderr, "Usage: <course_code> <term> <output_filename>\n");
        exit(0);
    }

    strtok(argv[3], "\n");

    class_list( argv[1], argv[2], argv[3] );

    return 0;

}
