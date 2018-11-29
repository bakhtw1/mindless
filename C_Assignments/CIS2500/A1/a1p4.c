#include <stdio.h>
#include <stdlib.h>
#include "tictactoe.h"


int main( int argc, char**argv){

     int i;
     int usNum;
     char b3[]    = "000000000";
     char bc[]    = "012345678";
     char board[] = "   |   |   \n---+---+---\n   |   |   \n---+---+---\n   |   |   \0";
     FILE *fin; 

     struct strategy_struct wrd;

     if(argc != 2){
         fprintf(stderr, "Usage: %s <board number (us)>\n", argv[0]);
         exit(-1);
     } 

     usNum = atoi( argv[1] );
     b3fromus(b3, usNum );
     boardfromb3(board, b3);

     fin = fopen("strategyfile", "r");
     

     fseek(fin, usNum * 2, SEEK_SET);
     fread(&wrd, sizeof(struct strategy_struct), 1, fin); 
      

     printf("\nBoard Number: %s\n", argv[1]);
     printf("Board b3: %s\n", b3);
     printf("Board Pic:\n%s\n", board);
     printf("Move: %d\n", get_move(b3));
     printf("Turn: %c\n", get_turn(b3));
     printf("Winner: %c\n", winner( usNum ));    
     printf("best_move=%d, winner=%c\n", wrd.best_move, wrd.winner); 
     

     for(i = 0; bc[i] != '\0'; i++){
 
             printf("%d -> %d\n", i ,next(usNum, bc[i]));
 
     }
   
     fclose(fin);
 
     return 0;

}
