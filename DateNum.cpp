#include "DateNum.h"

void DateNum::print() {
    updateClock();
    int l = showDay() + 1; // lunghezza della stringa del giorno e uno spazio
    mvprintw(y/2,x/4 + l,"%d/%d/%d",clock->getDayM(),clock->getMonth(),clock->getYear());
    refresh();
}