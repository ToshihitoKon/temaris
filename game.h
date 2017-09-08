#ifndef GAME_H
#define GAME_H

#include <curses.h>

int game_board[20][10];
int base_x;
int base_y;
int blockid;

static int block[7][3][2] = {
    { {1,0},{1,1},{0,1} },      // O
    { {1,0},{2,0},{-1,0} },     // I
    { {-1,0},{0,1},{0,-1} },    // T
    { {1,0},{0,-1},{-1,-1} },   // S
    { {1,0},{-1,0},{-1,-1} },   // L
    { {1,0},{0,1},{-1,1} },     // Z
    { {1,0},{-1,0},{-1,1} }     // J
};

void game_init();
void game_proc();
void game_draw(WINDOW *);

#endif
