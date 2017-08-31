#include "game.h"

void game_init()
{
    for(int i=0; i<20; i++)
        for(int j=0; j<10; j++)
            game_board[i][j]=0;

    game_board[0][0] = 1;
    game_board[1][0] = 1;
    game_board[2][0] = 1;
    game_board[3][0] = 1;
}

void game_proc()
{
    
}

void game_draw(WINDOW *wnd_main)
{
    for(int i=0; i<20; i++)
        for(int j=0; j<10; j++)
            if(game_board[i][j] != 0)
                mvwprintw(wnd_main, 1+i, 1+(j*2), "[]");
}
