#include <curses.h>
#include <locale.h>
#include <time.h>
#include <unistd.h>

#include "game.h"

int main(int args, char** argv)
{

    unsigned int usec = 16000;

    //fps count
    int fps_count = 0;
    int fps_print = 60;
    time_t prev = time(NULL), current;

    //setting
    setlocale(LC_ALL, "");
    initscr(); cbreak(); noecho();
    nonl();
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, true);

    //wnoutrefresh(stdscr);
    
    WINDOW *wnd[5];
    wnd[0] = subwin(stdscr, 22 ,22,  1,  1);
    wnd[1] = subwin(stdscr,  5 ,12,  1, 24);
    wnd[2] = subwin(stdscr,  5 ,12,  7, 24);
    wnd[3] = subwin(stdscr,  5 ,30, 14, 24);
    
    for(int i=0; i<3; i++) 
        box(wnd[i], ACS_VLINE, ACS_HLINE);
    
    game_init();

    while(true){
        //fps
        fps_count ++;
        current = time(NULL);
        if(prev != current){
            prev = current;
            fps_print = fps_count;
            fps_count = 0;
        }

        mvwprintw(wnd[1], 0, 2, " NEXT ");
        mvwprintw(wnd[2], 0, 2, " HOLD ");
        mvwprintw(wnd[3], 0, 0, "SCORE: ");
        mvwprintw(wnd[3], 1, 0, "LINES: ");
        mvwprintw(wnd[3], 2, 0, "LEVEL: ");
        mvwprintw(wnd[3], 3, 0, "FPS  : %d", fps_print);

        //proc
        game_proc();

        //draw
        game_draw(wnd[0]);

        //refresh
        for(int i=0; i<4; i++){
            wmove(wnd[i], 0,0);
            wnoutrefresh(wnd[i]);
        }

        refresh();

        usleep(usec);
    }
    delwin(wnd[0]);
    delwin(wnd[1]);
    delwin(wnd[2]);
    delwin(wnd[3]);
    endwin();

}


