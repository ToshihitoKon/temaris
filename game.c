#include "game.h"

int current_block[3][2];
int swp;

void game_init()
{
    for(int i=0; i<20; i++)
        for(int j=0; j<10; j++)
            game_board[i][j]=0;

    base_x = 5;
    base_y = 5;
    blockid = 3;

    for(int i=0; i<3; i++)
        for(int j=0; j<2; j++)
            current_block[i][j] = block[blockid][i][j];

    game_board[base_y][base_x] = 2;
    for(int i=0; i<3; i++)
        game_board[base_y + current_block[i][0]][base_x + current_block[i][1]] = 1;
}

void game_proc()
{
    static int key_code = -1;
    key_code = getch();
    if(key_code != ERR){
        game_board[base_y][base_x] = 0;
        for(int i=0; i<3; i++)
            game_board[base_y + current_block[i][0]][base_x + current_block[i][1]] = 0;

        switch(key_code){
        case KEY_DOWN:
            if(base_y < 19)
                base_y ++;
            break;
        case KEY_UP:
            if(0 < base_y)
                base_y --;
            break;
        case KEY_RIGHT:
            if(base_x < 9)
                base_x ++;
            break;
        case KEY_LEFT:
            if(0 < base_x)
                base_x --;
            break;
        case (int)'a':
            for(int i=0; i<3; i++){
                swp = current_block[i][0];
                current_block[i][0] = -current_block[i][1];
                current_block[i][1] = swp;
            }
            break;
        case (int)'d':
            for(int i=0; i<3; i++){
                swp = current_block[i][0];
                current_block[i][0] = current_block[i][1];
                current_block[i][1] = -swp;
            }
            break;
        case (int)'s':
            blockid++;
            if(blockid == 7)
                blockid = 0;
            for(int i=0; i<3; i++)
                for(int j=0; j<2; j++)
                    current_block[i][j] = block[blockid][i][j];
            break;

        }
        
        game_board[base_y][base_x] = 2;
        for(int i=0; i<3; i++)
            game_board[base_y + current_block[i][0]][base_x + current_block[i][1]] = 1;
    }
    
}

void game_draw(WINDOW *wnd_main)
{
    for(int i=0; i<20; i++)
        for(int j=0; j<10; j++)
            if(game_board[i][j] == 0)
                mvwprintw(wnd_main, 1+i, 1+(j*2), "  ");
            else if(game_board[i][j] == 2)
                mvwprintw(wnd_main, 1+i, 1+(j*2), "@@");
            else
                mvwprintw(wnd_main, 1+i, 1+(j*2), "[]");
}
