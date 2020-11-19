#include "DateNum.h"

void DateNum::print() {
    int y,x;
    showDay();
    getyx(stdscr,y,x);
    mvprintw(y,x+1,"%d/%d/%d",clock->getDayM(),clock->getMonth(),clock->getYear());
    refresh();
}