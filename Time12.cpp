#include "Time12.h"

Time12::Time12(Clock *c) : Time(c) {
    int hour = clock->getHour();
    if (hour>12){
        hour -= 12;
        AM = false;
    }
    else AM = true;
    clock->setHour(hour);
}

void Time12::print() {
    int col,row;
    getmaxyx(stdscr,col,row);
    init_pair(9,COLOR_RED,COLOR_CYAN);
    attron(COLOR_PAIR(9));
    mvprintw(col/4,row/2,"%u",clock->getHour());
    mvprintw(col/4,row/2+3,"%u",clock->getMinutes());
    mvprintw(col/4,row/2+6,"%u",clock->getSeconds());
    if (AM)
        mvprintw(col/4, row/2+9, "AM");
    else
        mvprintw(col/4, row/2+9, "PM");
    attroff(COLOR_PAIR(9));
    refresh();
    //getch();
}