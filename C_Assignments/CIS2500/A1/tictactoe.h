#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <stdio.h>
#include <stdlib.h>

struct strategy_struct
{
    char best_move;
    char winner;
};
 
unsigned short b3tous( char b3[10] );
void b3fromus( char b3[10], unsigned short us );
void boardtob3( char b3[10], char board[60] );
void boardfromb3( char board[60], char b3[10] );
char winner( unsigned short us );
unsigned short next( unsigned short us, char pos );
char get_move( char b3[10] );
char get_turn( char b3[10] );
void get_record(FILE *fp, unsigned short us, struct strategy_struct *record);
void set_record(FILE *fp, unsigned short us, struct strategy_struct *record);
void evaluate_move( unsigned short us, struct strategy_struct *record);

#endif
