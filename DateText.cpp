#include "DateText.h"

void DateText::print() {
    updateClock();
    showDay();
    int y,x;
    getyx(stdscr,y,x);
    mvprintw(y,x+1,"%d",clock->getDayM());
    showMonth();
    getyx(stdscr,y,x);
    mvprintw(y,x+1,"%d",clock->getYear());
    refresh();
}

void DateText::showMonth() {
    int y,x;
    getyx(stdscr,y,x);
    if (clock->getMonth() == 1) {
        char month[] = "January";
        mvprintw(y,x+1,"%s", month);
    }
    if (clock->getMonth() == 2) {
        char month[] = "February";
        mvprintw(y,x+1,"%s", month);
    }
    if (clock->getMonth() == 3) {
        char month[] = "March";
        mvprintw(y,x+1,"%s", month);
    }
    if (clock->getMonth() == 4) {
        char month[] = "April";
        mvprintw(y,x+1,"%s", month);
    }
    if (clock->getMonth() == 5) {
        char month[] = "May";
        mvprintw(y,x+1,"%s", month);
    }
    if (clock->getMonth() == 6) {
        char month[] = "June";
        mvprintw(y,x+1,"%s", month);
    }
    if (clock->getMonth() == 7) {
        char month[] = "July";
        mvprintw(y,x+1,"%s", month);
    }
    if (clock->getMonth() == 8) {
        char month[] = "August";
        mvprintw(y,x+1,"%s", month);
    }
    if (clock->getMonth() == 9) {
        char month[] = "September";
        mvprintw(y,x+1,"%s", month);
    }
    if (clock->getMonth() == 10) {
        char month[] = "October";
        mvprintw(y,x+1,"%s", month);
    }
    if (clock->getMonth() == 11) {
        char month[] = "November";
        mvprintw(y,x+1,"%s", month);
    }
    if (clock->getMonth() == 12) {
        char month[] = "December";
        mvprintw(y,x+1,"%s", month);
    }
}