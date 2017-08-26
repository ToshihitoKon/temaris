#include <curses.h>
#include <locale.h>
#include <unistd.h>

int main(int args, char** argv)
{
    setlocale(LC_ALL, "");
    initscr(); cbreak(); noecho();
    nonl();
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);

    wnoutrefresh(stdscr);
    
    WINDOW *wnd[4];
    wnd[0] = subwin(stdscr, 22 ,22,  1,  1);
    wnd[1] = subwin(stdscr,  5 ,12,  1, 24);
    wnd[2] = subwin(stdscr,  5 ,12,  7, 24);
    wnd[3] = subwin(stdscr,  5 ,30, 14, 24);
    
    for(int i=0; i<3; i++) 
        box(wnd[i], ACS_VLINE, ACS_HLINE);

    mvwprintw(wnd[1], 0, 2, " NEXT ");
    mvwprintw(wnd[2], 0, 2, " HOLD ");
    mvwprintw(wnd[3], 0, 0, "SCORE: ");
    mvwprintw(wnd[3], 1, 0, "LINES: ");
    mvwprintw(wnd[3], 2, 0, "LEVEL: ");

    for(int i=0; i<4; i++) 
        wrefresh(wnd[i]);

    doupdate();

    sleep(10);

    delwin(wnd[0]);
    delwin(wnd[1]);
    delwin(wnd[2]);
    delwin(wnd[3]);
    endwin();

}


