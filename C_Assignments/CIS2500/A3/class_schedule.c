/*
*  Name: Waqas Bakht
*  Course: CIS*2500
*  Instructor: Stefan Kremer
*  Assignment 4
*/

#include "aim.h"

int main(int argc, char *argv[])
{

    char ids[10];
    int id;
    struct student_struct *search;

    if(argc != 3)
    {
        fprintf(stderr, "Usage <student id> <term>\n");
        exit(0);
    }
    else
    {
        strcpy(ids, argv[1]);
        strtok(argv[2], "\n");
        
    }

    id = atoi(ids);

    search = get_student_info(id);

    if(search != NULL)
    {
        printf("Name: %s %s %s\nID: %07d\n", 
                      search->first_name,
                         search->middle_names,
                            search->last_name,
                                    search->id);
    }

    get_student_course_info(id, argv[2]);

    free(search);

    return 0;
}
