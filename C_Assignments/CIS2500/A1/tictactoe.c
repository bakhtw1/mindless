#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tictactoe.h"


void evaluate_move( unsigned short us, struct strategy_struct *record){

   int i, temp2, found_tie = 0, legal_move;
   FILE *fin;
   struct strategy_struct temp;
   char exb3[] = "000000000";

   fin = fopen("strategyfile", "r");

   b3fromus(exb3, us);

   for(i =0; i < 9; i++){
       if(next(us, i) == 0){
           
       }
       if(next(us, i) != 0){
           
           if(winner(next(us, i)) == get_turn(exb3) ){
               record->winner = get_turn(exb3);
               record->best_move = i;
               return;
           }
           else if(winner(next(us, i)) == '0'){
              temp2 = i;
              found_tie = 1; 
           }
           else{
               legal_move = i;
           }
     
       }
   }
  
   if(found_tie == 1){
       record->best_move = temp2;
       record->winner = '0';
   }
   else if(found_tie == 0){
       record->best_move = legal_move;
       if(get_turn(exb3) == '1'){
           record->winner = '2';
       }
       if(get_turn(exb3) == '2'){
           record->winner = '1';
       } 
   }

   fclose(fin);

}

void get_record(FILE *fp, unsigned short us, struct strategy_struct *record){

    fseek(fp, us , SEEK_SET);
    fread( record, sizeof(struct strategy_struct), 1, fp);
    
}

void set_record(FILE *fp, unsigned short us, struct strategy_struct *record){

    fseek(fp, us * 2, SEEK_SET);
    fwrite(&record, sizeof(struct strategy_struct), 1, fp);

}

void b3fromus( char b3[10], unsigned short us ){

    char base[] = "000000000";
    int divU = 0, modU = 0, i;
    int plaHo[10];
    int baseS[] = {6561, 2187, 729, 243, 81, 27, 9, 3, 1};

    plaHo[0] = us;

    for(i = 0; i < 9; i++){
        divU = plaHo[i] / baseS[i];
        if(divU == 2){
            base[i] = '2';
        }
        else if(divU == 1){
            base[i] = '1';
        }
        else{
            base[i] = '0';
        }
        modU = plaHo[i] % baseS[i];
        plaHo[i + 1] = modU;
    }

    strcpy(b3, base);

    return;
}

unsigned short b3tous( char b3[10] ){

    unsigned short plaHo = 0;
    unsigned short ntGer = 0;
    int i = 0;
    int baseD[] = {6561, 2187, 729, 243, 81, 27, 9, 3, 1};

    for(i = 0; i < 9; i++){

       if( b3[i] == '2' ){
            plaHo = 2 * baseD[i];
       }
       else if( b3[i] == '1' ){
            plaHo =  baseD[i];
       }
       ntGer = ntGer + plaHo;
       plaHo = 0;

    }

    return ntGer;
}

void boardtob3( char b3[10], char board[60]){

    int i, j = 0; 
    
        for (i = 0; i < strlen(board) - 1; i++){
       
            if (board[i] == 'X'){
               b3[j] = '2';
               j = j + 1;     
            }
            else if (board[i] == 'O'){
               b3[j] = '1';
               j = j + 1;
            }
            else {
               b3[j] = '0';
            }
        }    

    return;

}

void boardfromb3( char board[60], char b3[10]){

    int i, j = 0;

    for(i = 0; board[i] != '\0'; i++){

        if (board[i-1] == ' ' && board[i+1] == ' ' && board[i] != '|'){
           if (b3[j] == '2'){
              board[i] = 'X';
              j++;
           }
           else if(b3[j] == '1'){
              board[i] = 'O';
              j++;
           }
           else if(b3[j] == '0'){
              board[i] = ' ';
              j++;
           }
        }

    }


}

char winner(unsigned short us){

    int count = 0; 
    char outcome = ' ';
    char base[] = "000000000";    
    unsigned short int i;

    b3fromus(base, us);

    for(i = 0; base[i] != '\0'; i++ ){
       if(base[i] != '0' ){
            if(base[i + 1] == base[i] && base[i+2] == base[i] && (i % 3) == 0){
                outcome = base[i];
                break;    
            }
            else if(base[i + 3] == base[i] && base[i + 6] == base[i]){
                outcome = base[i];
                break;
            }
            else{
                outcome = ' ';
            }
            count++;
       } 
    }

    if(base[4] == base[0] && base[4] == base[8] && base[4] != '0'){
        outcome = base[4];
    }
    else if (base[4] == base[2] && base[4] == base[6] && base[4] != '0'){
        outcome = base[4];
    }
       
    if(count == 9 && outcome == ' '){
        outcome = '0';
    }

    return outcome;

}

unsigned short next(unsigned short us, char pos){

   char baseT[] = "000000000";
   int i, xcount = 0, ycount = 0;
   int posT = atoi(&pos);

   b3fromus(baseT, us);

   if(baseT[posT] != '0'){
       strcpy(baseT, "000000000");
   }
   else {
       for(i = 0; baseT[i] != '\0'; i++){
	   if(baseT[i] == '2'){
               xcount++;
           }
           else if(baseT[i] == '1'){
               ycount++;
           }
       }

       if(xcount == ycount){
           baseT[posT] = '2';
       } 
       else{
           baseT[posT] = '1';
       }

   }

   return b3tous(baseT);

}

char get_move( char b3[10] ){

    int i, count = 0;

    for(i = 0; b3[i] != '\0'; i++){
        if(b3[i] != '0'){
            count++;
        }            
    }

    return count; 

}

char get_turn( char b3[10] ){

    int i, xcount = 0, ocount = 0;

    for(i = 0; b3[i] != '\0'; i++){
        if( b3[i] == '2' ){
            xcount++;
        }  
        else if( b3[i] == '1' ){
            ocount++;
        }
    }
    if(xcount == ocount){
        return '2';
    }
    else{
        return '1';
    } 

}
