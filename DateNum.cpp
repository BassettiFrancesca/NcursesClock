#include "DateNum.h"

void DateNum::print() {
    updateClock();
    showDay();
    int y,x;
    getyx(stdscr,y,x);
    mvprintw(y,x+1,"%d/%d/%d",clock->getDayM(),clock->getMonth(),clock->getYear());
    refresh();
}