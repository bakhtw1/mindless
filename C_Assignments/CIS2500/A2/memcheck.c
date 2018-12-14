#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
* Author: Waqas Bakht (0981571)
* Date: March 2, 2018
* Assn: A3 - Linked List Memory Checker
* Class: CIS2500
* Prof: Stefan Kremer
* File: memcheck.c
*/

/* Structure to hold memory address, file name, file line, and a pointer to the next structure  */
struct linked_list 
{
    void   *ptr;
    char   *file;
    int    line;
    struct linked_list *next;  
};

/* 
*  Beginning of the linked list.
*  Instead of using double pointer fot the memcheck_free function, another global var 
*  is used to track the current node we are looking at. 
*/

struct linked_list *list_ptr = NULL;

/* Not needed anymore
struct linked_list *curr = NULL;
*/

char *strdup2( char *str )
{

    char *new;
    new = malloc( strlen(str)+1 );
    if (new)
    strcpy( new, str );
    return new;

}

int memcheck_main();
void print_list( struct linked_list *list_Ptr );
struct linked_list *searchlst(void *ptr, struct linked_list **prev);
int deleteNode(void *val);

int main() 
{
    memcheck_main();
    print_list( list_ptr );
    return 0;
}

void *memcheck_malloc( size_t size, char *file, int line )
{
  
    struct linked_list *new_item;
    void *temPtr;

    new_item = malloc( sizeof(struct linked_list) );

    /* Push node onto list and return ptr address*/

    new_item->file = strdup2(file);
    new_item->line = line;
    new_item->next = list_ptr;
    new_item->ptr = malloc( size ); 

    list_ptr = new_item;

    temPtr = new_item->ptr;

    return temPtr;

}


void *memcheck_calloc( size_t count, size_t size, char *file, int line )
{

    struct linked_list *new_item;
    void *ptr;

    new_item = malloc( sizeof(struct linked_list) );

    new_item->file = strdup2( file );
    new_item->line = line;
    new_item->next = list_ptr;
    new_item->ptr  = calloc( count, size );

    list_ptr = new_item;

    ptr = new_item->ptr;
 
    return ptr;

}


void memcheck_free( void *ptr, char *file, int line )
{

    /*  
    *   Instead of using a double pointer, i have created a function to delete a node from the list.
    *   This function is useful because it takes into consideration the beggining and the end of the list.
    */

    /*    
    int deli;

    deli = deleteNode(ptr);

    if(deli == 0)
    {
        return;
    }
    */  
    
    struct linked_list **dptr, *tmp; 
    

    for( dptr = &list_ptr; *dptr; dptr = &(*dptr)->next ) 
    {
  
        if( (*dptr)->ptr == ptr )
        {  
          
            tmp = (*dptr)->next;
            free( (*dptr)->ptr );
            free( (*dptr)->file );
            free( (*dptr) );
            *dptr = tmp;

            return; 

        }               
  
    }
  
    printf("memcheck error:  attempting to free memory address %p in file \"%s\", line %d.\n", (void *)ptr, file, line); 
}


void *memcheck_realloc( void *ptr, size_t size, char *file, int line )

/* 
*    Go through the list find the matching memory location, realloc the ptr member, set the file and line values to the newly substituded ones.
*    Also return the value of the ptr member to get the reallocated memory.
*/

/*
*    Free the corresponding node to the ptr, then return the new malloc.
*/

{

    void *ret;

    memcheck_free(ptr, file, line);
   
    ret = memcheck_malloc(size, file, line);

    return ret;    


    /*    
    struct linked_list *search;
    void *temp;

    search = list_ptr;

    while(search)
    {
        if(search->ptr == ptr)
        {

            search->ptr = realloc(search->ptr, size);
            search->file = file;
            search->line = line;
            temp = search->ptr;          
          
        }

        search = search->next;

    }

    return temp;

    */
}


void print_list( struct linked_list *list_Ptr )

/*
*   Print out each memory address that is in the list. 
*/

{
    while(list_Ptr)
    {
        printf("memcheck error:  memory address %p which was allocated in file \"%s\", line %d, was never freed\n", list_Ptr->ptr, list_Ptr->file, list_Ptr->line );
        list_Ptr = list_Ptr->next;        
    }

}


/*
***********************************************************************************
*    The two functions searchlst and deleteNode I have created                    *
*    because I could not understand the usage of the double pointer described     *
*    in day 4 of the online disscussions.                                         *
*                               
***********************************************************************************

struct linked_list *searchlst(void *val, struct linked_list **prev)

*    Search through the linked list for val.
*    Return NULL if it doesn't exist in the list.
*    Otherwise return the ptr.


{   
     struct linked_list *ptr = list_ptr;
     struct linked_list *tmp = NULL;
     bool found = false;
     
     
     while(ptr != NULL)
     {   
         if(ptr->ptr == val)
         {   
             found = true;
             break;
         }
         else
         {   
             tmp = ptr;
             ptr = ptr->next;
         }
     }
 
     if(true == found)
     {
         if(prev)
             *prev = tmp;
         return ptr;
     }
     else
     {
         return NULL;
     }
}

int deleteNode(void *val)

*    If the call to search_in_list returns NULL return from the function 
*    with indication that it did not find anything to delete.
*    Otherwise delete the node which corresponds to the val being passed to the function..

{   
     struct linked_list *prev = NULL;
     struct linked_list *del = NULL;
     
     
     del = searchlst(val,&prev);
     if(del == NULL)
     {   
         return -1;
     }
     else
     {   
         if(prev != NULL) 
             prev->next = del->next;
         
         if(del == curr)
         {   
             curr = prev;
         }
         else if(del == list_ptr)
         {   
             list_ptr = del->next;
         }
     }
     
     free(del->ptr);
     free(del);
     del = NULL;
     
     return 0;
}
*/
