#include <stdio.h>

void BannerPrint(void)
{
    char name[30];
    printf("Enter your first name: ");
    scanf("%s", name);

    printf("**********************************************\n");
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf("**********************************************\n");
    printf("\tWelcome to week 7 lab %s\n", name);
    printf("**********************************************\n");
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf("**********************************************\n");

}

int main (void)
{

    BannerPrint();

}
