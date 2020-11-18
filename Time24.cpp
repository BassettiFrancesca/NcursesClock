#include "Time24.h"

void Time24::print() {
    int row;
    int col;
    getmaxyx(stdscr,col,row);
    init_pair(10,COLOR_RED,COLOR_CYAN);
    attron(COLOR_PAIR(10));
    mvprintw(col/4,row/2,"%u",clock->getHour());
    mvprintw(col/4,row/2+3,"%u",clock->getMinutes());
    mvprintw(col/4,row/2+6,"%u",clock->getSeconds());
    attroff(COLOR_PAIR(10));
    refresh();
    //getch();
}

void Time24::printT() {
    int row;
    int col;
    getmaxyx(stdscr,col,row);
    init_pair(10,COLOR_RED,COLOR_CYAN);
    attron(COLOR_PAIR(10));
    mvprintw(col/4,row/2,"%u",clock->getHour());
    mvprintw(col/4,row/2+3,"%u",clock->getMinutes());
    mvprintw(col/4,row/2+6,"%u",clock->getSeconds());
    attroff(COLOR_PAIR(10));
    refresh();
}