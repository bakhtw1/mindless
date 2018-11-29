#include <stdio.h>
#include <stdlib.h>
#include "tictactoe.h"



int main ( int argc, char **argv ){
 
    int i;
    unsigned short usNum;
    char b3[]    = "000000000";
    char bc[]    = "012345678";
    char board[] = "   |   |   \n---+---+---\n   |   |   \n---+---+---\n   |   |   \0";  
    
    if(argc != 2){
        fprintf(stderr, "Usage: %s <board number (us)>\n", argv[0]);
        exit(-1);
    }

    usNum = atoi( argv[1] );

    b3fromus(b3, usNum );

    boardfromb3(board, b3);

    printf("\nBoard number: %s\n", argv[1]);
    printf("Board b3: %s\n", b3);
    printf("Board pic:\n%s\n", board);    
    printf("Move: %d\n", get_move(b3));
    printf("Turn: %c\n", get_turn(b3));
    printf("Winner: %c\n", winner( usNum )); 

    for(i = 0; bc[i] != '\0'; i++){

            printf("%d -> %d\n", i ,next(usNum, bc[i]));
       
    }

    printf("\n"); 

    return 0; 

}

