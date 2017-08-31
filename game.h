#ifndef GAME_H
#define GAME_H

#include <curses.h>

int game_board[20][10];

void game_init();
void game_draw(WINDOW *);

#endif
