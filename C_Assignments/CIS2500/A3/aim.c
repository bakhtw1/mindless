
/*
*  Name: Waqas Bakht
*  Course: CIS*2500
*  Instructor: Stefan Kremer
*  Assignment 4
*/

#include "aim.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int compar_id(const void *a, const void *b)
/* Sort student_structs by id member  */
{

    const struct student_struct *struct_a, *struct_b;

    struct_a = a;
    struct_b = b;

    return ((struct_a->id) - (struct_b->id));

}

void init_aim()
/* Initialize bin files */
{
    FILE *stu;

    stu = fopen("students.bin", "wb");
    fclose(stu);

    stu = fopen("courses.bin", "wb");
    fclose(stu);
    
    stu = fopen("student_course.bin", "wb");
    fclose(stu);
}

void register_student()
/* Register a student (add student struct to bin file) */
{
    
    struct student_struct new_stu, readf;
    char token[64];
    FILE *fptr;
    int lrgst = 0, k = 1;

    fptr = fopen("students.bin", "rb+"); 
    
    if(fptr == NULL)
    {
        fprintf(stderr, "FILE COULD NOT BE READ\n");
        exit(0);
    }    

    while( !feof(fptr) )
    {
        if( fread(&readf, sizeof(struct student_struct), 1, fptr) )
        {
            /* Check to see if file is corrupted */
            if( ftell( fptr ) == ( k * sizeof(struct student_struct) ) )
            {
                /* Check for largest id value in the file*/
                if(readf.id > lrgst)
                { 
                    lrgst = readf.id;
                }
            }
            else
            { 
                fprintf(stderr, "FILE IS CORRUPTED\n Run ./init_aim to reset files\n");
                exit(-1); 
            }
            k++;
        }
    }

    /* Create struct and append to the file */
    new_stu.id = lrgst + 1;

    printf("Last name: ");
    fgets(token, 64, stdin);
    strtok(token, "\n");
    strcpy(new_stu.last_name, token);
    
    printf("First name: ");
    fgets(token, 64, stdin);
    strtok(token, "\n");
    strcpy(new_stu.first_name, token);
    
    printf("Middle names: ");
    fgets(token, 64, stdin);
    strtok(token, "\n");
    strcpy(new_stu.middle_names, token);
    
    printf("Major: ");
    fgets(token, 64, stdin);
    strtok(token, "\n");
    strcpy(new_stu.major, token);

    fwrite(&new_stu, sizeof(struct student_struct), 1, fptr);

    fclose( fptr );

}

void sort()
/* Using the qsort function, sort the structures in the file by overwriting the file */
{
    
    FILE *fp;
    int i = 0, j = 0, k = 0;
    struct student_struct *order;

    fp = fopen("students.bin", "rb+");

    if( fp == NULL )
    {
        fprintf(stderr, "FILE COULD NOT BE READ");
        exit(0);
    }

    fseek(fp, 0, SEEK_END);

    k = ftell(fp)/sizeof(struct student_struct);

    order = calloc( k, sizeof(struct student_struct) );

    fseek(fp, 0, SEEK_SET);

    while( !feof(fp) )
    {
        if( fread( &order[i], sizeof(struct student_struct), 1, fp ) )
        {
            i++;
        } 
        
    }

    qsort( order, i, sizeof(struct student_struct), compar_id );

    fseek(fp, 0, SEEK_SET);

    while( j < i )
    {
        fwrite( &order[j], sizeof(struct student_struct), 1, fp );
        j++;
    } 

    free(order);

    fclose(fp);

}

void schedule()
/* Append a course_struct to the end of the courses.bin file */
{

    FILE *fp;  
    struct course_struct add_course;
    char token1[20];
    char token2[10];
    char token3[128];
    char token4[64];

    fp = fopen("courses.bin", "a");

    if(fp == NULL)
    {
        fprintf(stderr, "FILE COULD NOT BE OPENED\n");
        exit(0);
    }

    printf("Code: ");
    fgets( token1 , 20, stdin);
    strtok(token1, "\n");
    strcpy(add_course.code, token1);    

    printf("Term: ");
    fgets( token2, 10, stdin);
    strtok(token2, "\n");
    strcpy(add_course.term, token2);

    printf("Title: ");
    fgets( token3, 128, stdin);
    strtok(token3, "\n");
    strcpy(add_course.title, token3);

    printf("Insructor: ");
    fgets( token4, 128, stdin );
    strtok( token4, "\n" );
    strcpy( add_course.instructor, token4 );

    fwrite( &add_course, sizeof(struct course_struct), 1, fp );     

    fclose(fp);
    
}

void add()
/* Add a student_course_struct to the student_course.bin file */
{

    FILE *fp;
    struct student_course_struct stu;
    char temp[20];

    fp = fopen("student_course.bin", "a");

    if(fp == NULL)
    {
        fprintf(stderr, "FILE COULD NOT BE OPENED\n");
        exit(0);
    }

    printf("Student ID: ");
    fgets(temp, 20, stdin);
    stu.student_id = atoi(temp);

    printf("Course Code: ");
    fgets(temp, 20, stdin);
    strtok(temp, "\n");
    strcpy(stu.course_code, temp);

    printf("Term: ");
    fgets(temp, 20, stdin);
    strtok(temp, "\n");
    strcpy(stu.term, temp);
  
    printf("Registration [CRD or AUD]: ");
    fgets(temp, 20, stdin);
    strtok(temp, "\n");

    while( (strcmp(temp, "AUD") != 0) && (strcmp(temp, "CRD") != 0) )
    {
        printf("Registration [CRD or AUD]: ");
        fgets(temp, 20, stdin);
        strtok(temp, "\n");
    }

    strcpy(stu.registration, temp);

    stu.grade = -1;    

    fwrite(&stu, sizeof(struct student_course_struct), 1, fp);

    fclose(fp);

}

struct student_struct *get_student_info(int id)
/* Grab a student from the register by doing a binary search for the student id */
{

    FILE *fin;
    struct student_struct *stuptr;
    unsigned int n1 = 0, n2, mid;

    stuptr = malloc(sizeof(struct student_struct));
    fin = fopen("students.bin", "rb");

    fseek(fin, 0, SEEK_END);
    n2 = ftell(fin)/sizeof(struct student_struct);

    while(n1 != n2)
    {     
        mid = n1/2 + n2/2 + (n1%2 + n2%2)/2;
        fseek(fin, mid*sizeof(struct student_struct), SEEK_SET);
        fread(stuptr, sizeof(struct student_struct), 1, fin);

        if(id == stuptr->id)
        {
            fclose(fin);
            return stuptr;
        }
        else if(id < stuptr->id)
        {
            n2 = mid;
        }
        else if(id > stuptr->id)
        {
            n1 = mid + 1;
        }
        
    }    

    free(stuptr);
    fclose(fin);
    return NULL;
    
}

/* first linked list only holds data for a student_course_struct  */
struct linked_list *new_item(struct student_course_struct item)
{

    struct linked_list *new_node;

    new_node = malloc(sizeof(struct linked_list));
    memcpy( &(new_node->data), &item, sizeof(struct student_course_struct) );
    new_node->next = NULL;

    return new_node;

}

/* Push new nde onto list by order of course_code alphabetically*/
void pushbycode(struct linked_list **list, struct linked_list *node)
{
    
    while((*list) != NULL && strcmp( node->data.course_code, (*list)->data.course_code ) > 0 )
    {
        list = &(*list)->next;
    }

    node->next = *list;
    *list = node;

}

struct course_struct get_course( char course_look[] )
/* Function to search for a particular course  */
{
    FILE *courses;
    struct course_struct *retptr, bad;
    int num, i;

    strcpy(bad.code, " ");
    strcpy(bad.term, " ");
    strcpy(bad.title, " ");
    strcpy(bad.instructor, " ");

    courses = fopen("courses.bin", "rb");

    if(courses == NULL)
    {
        fprintf(stderr, "Cannot Open File\n");
        exit(-1);
    }

    fseek(courses, 0, SEEK_END);
    num = ftell(courses)/sizeof(struct course_struct);

    retptr = calloc(num, sizeof(struct course_struct));

    fseek(courses, 0, SEEK_SET);
    fread(retptr, num * sizeof(struct course_struct), 1, courses);

    for(i = 0; i < num; i++)
    {
        if(strcmp(retptr[i].code, course_look) == 0)
        {  
            fclose(courses);
            return retptr[i];
        }

    }

    fclose(courses);
    return bad;
}

void print_list( struct linked_list *list )
/* Print linked list, free any associated memory  */
{

    struct linked_list *temp;
    struct course_struct cour;

    while(list)
    {
        temp = list->next;
        cour = get_course(list->data.course_code);
        printf("%s %s\n%s\n", list->data.course_code, cour.title, cour.instructor);
        free(list);
        list = temp;
    }

}

void get_student_course_info( int id, char term[] )
/* Get the students course information */
{

    FILE *file;
    int num_entries, i;
    struct student_course_struct *read;
    struct linked_list *llhead = NULL, *add_item;

    file = fopen("student_course.bin", "r");

    fseek(file, 0, SEEK_END);
    num_entries = ftell(file)/sizeof(struct student_course_struct);

    read = calloc(num_entries, sizeof(struct student_course_struct));

    fseek(file, 0, SEEK_SET);    

    fread(read, num_entries * sizeof(struct student_course_struct), 1, file);

    for(i = 0; i < num_entries; i++)
    {  
        if(id == read[i].student_id && strcmp(term, read[i].term) == 0)
        {        
            add_item = new_item(read[i]);
            pushbycode(&llhead, add_item); 
        }
    }
 
    print_list(llhead);

    free(read);
    fclose(file);

}

/*Linked List 2!!*/
struct linked_list2 *new_item2(struct student_course_struct item, struct student_struct student_toadd)
/* Create node with data for a struct student_struct and a student_course_struct */
{
    
    struct linked_list2 *new_node;
    
    new_node = malloc(sizeof(struct linked_list2));
    memcpy( &(new_node->reg), &item, sizeof(struct student_course_struct) );
    memcpy( &(new_node->stud), &student_toadd, sizeof(struct student_struct));
    new_node->next = NULL;
    
    return new_node;

}

void pushbyname(struct linked_list2 **list, struct linked_list2 *node)
/* PUsh node onto linked list2 only this time we sort by last_name  */
{
    
    while((*list) != NULL && strcmp( node->stud.last_name, (*list)->stud.last_name ) > 0 )
    {  
        list = &(*list)->next;
    }
    
    node->next = *list;
    *list = node;

}

void print_list2( struct linked_list2 *list, char filename[], char code[], char name[] )
/* Print linked list into file free any associated memory while printing */
{

    struct linked_list2 *temp;
    FILE *classlist;

    classlist = fopen(filename, "w");

    fprintf(classlist, "%s %s\n", code, name);

    while(list)
    {   
        temp = list->next;
        fprintf(classlist, 
                    "%s, %s %s (%s)\n", 
                    list->stud.last_name, 
                         list->stud.first_name, 
                            list->stud.middle_names, 
                                list->stud.major);
        free(list);
        list = temp;
    }   

    fclose(classlist);

}

/*Linked List 2!!*/

void class_list( char course_code[], char term[], char filename[] )
/* Search for the correct student information a course and add this information to the linked list*/
/* This information will then be printed out the the txt file */
{

    FILE *stucour;
    struct student_course_struct *scsearch = NULL;
    struct course_struct courseinfo;
    struct student_struct *studsearch;
    struct linked_list2 *llhead = NULL, *item;
    int numscs, i;

    courseinfo = get_course(course_code);

    stucour = fopen("student_course.bin", "rb");

    if(stucour == NULL)
    {
        fprintf(stderr, "FILES COULD NOT BE OPENED\n");
        exit(0);
    }

    fseek(stucour, 0, SEEK_END);
    numscs = ftell(stucour)/sizeof(struct student_course_struct);
    fseek(stucour, 0, SEEK_SET);

    scsearch = calloc(numscs, sizeof(struct student_course_struct)); 

    fread(scsearch, numscs * sizeof(struct student_course_struct), 1, stucour);

    fclose(stucour);

    for( i = 0; i < numscs; i++ ) 
    {  
        if( strcmp(scsearch[i].course_code, course_code) == 0 && strcmp(scsearch[i].term, term) == 0 ) 
        { 
            studsearch = get_student_info(scsearch[i].student_id);
            if(studsearch != NULL)
            {
                item = new_item2(scsearch[i], *studsearch);
                pushbyname(&llhead, item);
            }
        }
    }

    print_list2(llhead, filename, courseinfo.code, courseinfo.title);

    free(studsearch);
    free(scsearch); 

}

void grade(char filen[])
/* This will go through the updated text file and add the nwe grade information to the student_course.bin file */
{

    FILE *stuc;
    FILE *text;
    struct student_course_struct *read;
    struct student_struct *student;
    char buffer[500];
    char buffer2[500];
    char *token;
    char course_code[15];

    stuc = fopen("student_course.bin", "r+");
    read = malloc(sizeof(struct student_course_struct));

    while(!feof(stuc))
    {
        if(fread(read, sizeof(struct student_course_struct), 1, stuc))
        {
            student = get_student_info(read->student_id);
            if(student != NULL)
            {
                sprintf(buffer, "%s, %s %s (%s)", student->last_name, student->first_name, student->middle_names, student->major);
                text = fopen(filen, "r"); 
                fgets(buffer2, 100, text);
                strncpy(course_code, buffer2, 15);
                strtok(course_code, " ");
                while(!feof(text))
                {
                    if(fgets(buffer2, 100, text))
                    {
                        token = strtok(buffer2, "\n\r");
                        if( strncmp(buffer2, buffer, strlen(buffer)) == 0 && strcmp(read->course_code, course_code) == 0)
                        {    
                            token = strtok(buffer2, "-/,?.()abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ \n\r");
                            if(token != NULL)
                            {
                                read->grade = atoi(token);
                                fseek(stuc, -sizeof(struct student_course_struct), SEEK_CUR);
                                fwrite(read, sizeof(struct student_course_struct), 1, stuc);
                            }
                        }
                    }
                }
                fclose(text);
            }
        }
    }

    free(student);
    free(read);
    fclose(stuc);

}

void print_list_with_grade( struct linked_list *list )
/* This function is similar to class_schedule only this will also print the grades  */
{
    struct linked_list *temp;
    struct course_struct cour;

    while(list)
    {
        temp = list->next;
        cour = get_course(list->data.course_code);
        printf("%s %s %d\n%s\n", list->data.course_code, cour.title, list->data.grade, cour.instructor);
        free(list);
        list = temp;
    }
}

void report( int id, char term[] )
/* This will add the updates student_course_structs to a linked list and print them out including the grade */
{

    FILE *file;
    int num_entries, i;
    struct student_course_struct *read;
    struct student_struct *bankroll;
    struct linked_list *llhead = NULL, *add_item;

    bankroll = get_student_info(id);

    if(bankroll == NULL)
    {
        fprintf(stderr, "Student Not Registered (./register to add student)\n");
        exit(0);
    }

    file = fopen("student_course.bin", "r");

    if(file == NULL)
    {
        fprintf(stderr, "FILE COULD NOT BE OPENED\n");
        exit(0);
    }

    fseek(file, 0, SEEK_END);
    num_entries = ftell(file)/sizeof(struct student_course_struct);

    read = calloc(num_entries, sizeof(struct student_course_struct));

    fseek(file, 0, SEEK_SET);

    fread(read, num_entries * sizeof(struct student_course_struct), 1, file);

    fclose(file);

    for(i = 0; i < num_entries; i++)
    { 
        if(id == read[i].student_id && strcmp(term, read[i].term) == 0)
        {      
            add_item = new_item(read[i]);
            pushbycode(&llhead, add_item);
        }
    }

    printf("Name: %s %s %s\n", bankroll->first_name, bankroll->middle_names, bankroll->last_name);
    printf("ID: %07d\n", bankroll->id);
    print_list_with_grade(llhead);

    free(read);

}












