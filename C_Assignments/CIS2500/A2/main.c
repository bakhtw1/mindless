#include <stdio.h>
#include <stdlib.h>
#include "memcheck.h"

int main()
{

   char *ptr1, *ptr2, *ptr3;

   ptr1 = malloc( 27 );

   ptr2 = malloc( 30 );
  
   ptr3 = malloc( 30 );
  
   ptr2 = realloc( ptr2, 31 ); 

   free( ptr3 );

   free( ptr2 );

   free( NULL );

   ptr1 = realloc( ptr1, 20 );

   return 0;

}



