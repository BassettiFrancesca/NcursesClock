#include "Date.h"

void Date::showDay() {
    int y,x;
    getmaxyx(stdscr,y,x);
    if (clock->getDayW() == 1) {
        char dayW[] = "Monday";
        mvprintw(y/2,x/2,"%s", dayW);
    }
    if (clock->getDayW() == 2) {
        char dayW[] = "Tuesday";
        mvprintw(y/2,x/2,"%s", dayW);
    }
    if (clock->getDayW() == 3) {
        char dayW[] = "Wednesday";
        mvprintw(y/2,x/2,"%s", dayW);
    }
    if (clock->getDayW() == 4) {
        char dayW[] = "Thursday";
        mvprintw(y/2,x/2,"%s", dayW);
    }
    if (clock->getDayW() == 5) {
        char dayW[] = "Friday";
        mvprintw(y/2,x/2,"%s", dayW);
    }
    if (clock->getDayW() == 6) {
        char dayW[] = "Saturday";
        mvprintw(y/2,x/2,"%s", dayW);
    }
    if (clock->getDayW() == 0) {
        char dayW[] = "Sunday";
        mvprintw(y/2,x/2,"%s", dayW);
    }
}