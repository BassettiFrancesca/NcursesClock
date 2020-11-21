#include "DateText.h"

void DateText::print() {
    updateClock();
    showDay();
    mvprintw(y/2,x/2 + 10,"%d",clock->getDayM());
    showMonth();
    mvprintw(y/2,x/2 + 23,"%d",clock->getYear());
    refresh();
}

void DateText::showMonth() {
    if (clock->getMonth() == 1) {
        char month[] = "January";
        mvprintw(y/2,x/2 + 13,"%s", month);
    }
    if (clock->getMonth() == 2) {
        char month[] = "February";
        mvprintw(y/2,x/2 + 13,"%s", month);
    }
    if (clock->getMonth() == 3) {
        char month[] = "March";
        mvprintw(y/2,x/2 + 13,"%s", month);
    }
    if (clock->getMonth() == 4) {
        char month[] = "April";
        mvprintw(y/2,x/2 + 13,"%s", month);
    }
    if (clock->getMonth() == 5) {
        char month[] = "May";
        mvprintw(y/2,x/2 + 13,"%s", month);
    }
    if (clock->getMonth() == 6) {
        char month[] = "June";
        mvprintw(y/2,x/2 + 13,"%s", month);
    }
    if (clock->getMonth() == 7) {
        char month[] = "July";
        mvprintw(y/2,x/2 + 13,"%s", month);
    }
    if (clock->getMonth() == 8) {
        char month[] = "August";
        mvprintw(y/2,x/2 + 13,"%s", month);
    }
    if (clock->getMonth() == 9) {
        char month[] = "September";
        mvprintw(y/2,x/2 + 13,"%s", month);
    }
    if (clock->getMonth() == 10) {
        char month[] = "October";
        mvprintw(y/2,x/2 + 13,"%s", month);
    }
    if (clock->getMonth() == 11) {
        char month[] = "November";
        mvprintw(y/2,x/2 + 13,"%s", month);
    }
    if (clock->getMonth() == 12) {
        char month[] = "December";
        mvprintw(y/2,x/2 + 13,"%s", month);
    }
    refresh();
}