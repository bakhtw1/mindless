#ifndef AIM_H
#define AIM_H

/*
*  Name: Waqas Bakht
*  Class: CIS*2500
*  Instructor: Stefan Kremer
*  Assignment 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student_struct 
{
    char last_name[64];
    char first_name[64];
    char middle_names[64];
    int id;
    char major[64];
};

struct course_struct
{
    char code[10];
    char term[6];
    char title[128];
    char instructor[64];
};

struct student_course_struct
{
    int student_id;
    char course_code[10];
    char term[6];
    char registration[4];
    int grade;
};

struct linked_list
{
    struct student_course_struct data;
    struct linked_list *next;
};

struct linked_list2
{
    struct student_course_struct reg;
    struct student_struct stud;
    struct linked_list2 *next;
};

void init_aim();
void register_student();
void sort();
void schedule();
void add();
void get_student_course_info(int id, char term[]);
void class_list( char course_code[], char term[], char filename[] );
void grade(char fileN[]);
void report(int id, char term[]);
void pushbycode(struct linked_list **list, struct linked_list *node);
void print_list( struct linked_list *list );
void pushbyname(struct linked_list2 **list, struct linked_list2 *node);
void print_list2( struct linked_list2 *list, char filename[], char code[], char name[] );
void print_list_with_grade( struct linked_list *list );

int compar_id(const void *a, const void *b);

struct linked_list *new_item(struct student_course_struct item);
struct course_struct get_course( char course_look[] );
struct student_struct *get_student_info(int id);
struct linked_list2 *new_item2(struct student_course_struct item, struct student_struct student_toadd);

#endif
