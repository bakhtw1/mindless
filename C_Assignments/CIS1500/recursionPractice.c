#include <stdio.h>

long long factorial(long long n);
void printFactorial(long long n);

int main (void){

     long long n = 0;
     printf("Enter a number: ");
     scanf("%lld", &n);
     printFactorial(n);
//     factorial(n);

}

long long factorial(long long n)
{
     long long ans = 0;
     if(n == 0 || n == 1){
         ans = 1;
     }
     else{
         ans = n * factorial(n - 1);
     }

     return ans;

}

void printFactorial(long long n){

     printf("%lld! = ", n);
     for(int i = n; i > 0; i--){
         if(i == 1){
             printf("%d", i);
         }
         else{
             printf("%d x ", i);
         }
     }
     printf(" = %lld\n", factorial(n));

}

