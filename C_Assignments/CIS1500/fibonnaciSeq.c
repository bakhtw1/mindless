#include <stdio.h>

void printNextFib(int n);

int main (void){

     printf("%d, %d, ", 0, 1);

     printNextFib(30);

     printf("\n");
}

void printNextFib(int n){

     static int prN1 = 0, prN2 = 1, nxtN;

     if(n != 0)
     {
          nxtN = prN1 + prN2;

          prN1 = prN2;

          prN2 = nxtN;

          printf("%d, ", nxtN);

          printNextFib(n - 1);
     }

}
