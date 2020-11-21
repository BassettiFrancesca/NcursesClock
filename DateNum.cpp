#include "DateNum.h"

void DateNum::print() {
    updateClock();
    showDay();
    mvprintw(y/2,x/2 + 10,"%d/%d/%d",clock->getDayM(),clock->getMonth(),clock->getYear());
    refresh();
}