#include <stdio.h>
#include <stdlib.h>
#include "tictactoe.h"

int main( int argc, char **argv){

    char b3[] = "000000000";
    char fName[] = "strategyfile";
    FILE *fout; 
    int i, move, temp = 0, found_tie = 0, legal_move;
    char j;

    struct strategy_struct wrnb;
    struct strategy_struct newn;

    if(argc != 2){
        fprintf(stderr, "Usage: %s <move number>\n", argv[0]);
        exit(-1);
    }

    move = atoi(argv[1]);  
    fout = fopen(fName, "rb+");
    
    for(i = 0; i < 19683; i++){
    
        b3fromus(b3, i);
        if( get_move(b3) == move ){ 

            if(winner(i) != ' '){
                 wrnb.winner = winner(i);
                 wrnb.best_move = -1;                                   
            }
            if(winner(i) == ' ')
            {
                for(j = 0; j < 9; j++){
                  
                  if(next(i, j) != 0){
                    
                    fseek(fout, i*2, SEEK_SET);
                    fread(&newn, sizeof(struct strategy_struct), 1, fout);
                    if( newn.winner == get_turn(b3) ){
                        wrnb.winner = newn.winner;
                        wrnb.best_move = j;
                        break;
                    }
                    else if ( newn.winner == '0' ){
                        temp = i; 
                        found_tie = 1;                    
                    }
                    else {
                         legal_move = i;
                    }
        
                  }
                }
 
                if(found_tie == 1){ 
                    wrnb.best_move = 1;
                    wrnb.winner = '0';
                }   
                else if(found_tie == 0){
                    wrnb.best_move = legal_move;
                    if(get_turn(b3) == '1'){
                       wrnb.winner = '2';
                    }
                    if(get_turn(b3) == '2'){
                       wrnb.winner = '1';
                    }   
                }
           

             /*evaluate_move(i, &wrnb);*/

             }
            fseek(fout, i*2, SEEK_SET);
            fwrite(&wrnb, sizeof(struct strategy_struct), 1, fout);

        }
        
        
    }
 
    printf("\n");
    fclose(fout);
    
}
