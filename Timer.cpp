#include "Timer.h"
#include "Time24.h"

void Timer::getInput() {
    int y,x;
    getmaxyx(stdscr,y,x);
    int selected = 0;
    clear();
    mvprintw(y/2,x/2,"Select how many hours should pass");
    //fare menu a tendina per ore minuti secondi (ENTER = 10)
    clear();
}

void Timer::stopAt() {
    int y,x;
    getmaxyx(stdscr,y,x);
    // fare che si ferma quando i 2 orologi sono == usando updateClock in time24
    clear();
    attron(A_BLINK);
    mvprintw(y/2,x/2,"TIME IS UP!");
    attron(A_BLINK);
    mvprintw(y/2 + 2,x/2,"press any key to exit");
    attroff(A_BOLD);
    getch();
    endwin();
}