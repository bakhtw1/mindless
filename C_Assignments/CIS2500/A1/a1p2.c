#include <stdio.h>
#include <stdlib.h>
#include "tictactoe.h"

int main(void){

    int i;
    char fileName[] = "strategyfile";
    FILE *fout; 
    struct strategy_struct wrb;

    wrb.winner = ' ';
    wrb.best_move = -1; 

    fout = fopen( fileName, "wb");

    for(i = 0; i < 19683; i++){
        fwrite(&wrb, sizeof(wrb), 1, fout);
    }   
 
    fclose(fout);

    return 0;
}
