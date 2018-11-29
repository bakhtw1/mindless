#include <stdio.h>

int funXYZ(int *, int *, int *, int);
int a = 3, b = 4, c = 11;

int main(void){

     int p, y = 3;

     a = 9; b = 10;

     p = funXYZ(&a, &b, &y, c);

     printf("a in main = %d \n", a);
     printf("b in main = %d \n", b);
     printf("c in main = %d \n", c);
     printf("p in main = %d \n", p);
     printf("y in main = %d \n", y);

     return 0;

}

int funXYZ(int * u, int * v, int *w, int z){

     int x;
     a = *u + b;
     x = *w;
     *v = a;
     x = *v % z;

     printf("a in funXYZ = %d \n", a);
     printf("b in funXYZ = %d \n", b);
     printf("c in funXYZ = %d \n", c);
     printf("x in funXYZ = %d \n", x);

     return x + *u;

}
