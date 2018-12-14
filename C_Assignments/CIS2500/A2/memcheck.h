
/*
*    Author: Waqas Bakht (0981571)
*    Date: March 2, 2018
*    Assn: A3 Linked List Memory Checker
*    Class: CIS2500  
*    Prof: Stefan Kremer 
*    File: memcheck.h
*/

#ifndef MEMCHECK_H
#define MEMCHECK_H

#include <stdio.h>
#include <stdlib.h>

#define main                     memcheck_main
#define malloc( size )           memcheck_malloc( size, __FILE__, __LINE__)  
#define calloc( count, size )    memcheck_calloc( count, size, __FILE__, __LINE__)  
#define free( ptr )              memcheck_free( ptr, __FILE__, __LINE__)    
#define realloc( ptr, size )     memcheck_realloc( ptr, size, __FILE__, __LINE__) 

int  memcheck_main();
void *memcheck_malloc( size_t size, char *file, int line );
void *memcheck_calloc( size_t count, size_t size, char *file, int line );
void memcheck_free( void *ptr, char *file, int line );
void *memcheck_realloc( void *ptr, size_t size, char *file, int line );

#endif
