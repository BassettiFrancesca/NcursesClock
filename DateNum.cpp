#include "DateNum.h"

//anche qua mostra giorni testuali
void DateNum::print() {
    int row;
    int col;
    init_pair(5,COLOR_RED,COLOR_CYAN);
    attron(COLOR_PAIR(5));
    getmaxyx(stdscr,col,row);
    mvprintw(col/2,row/2,"%u",clock->getDayW());
    mvprintw(col/2,row/2+3,"%u",clock->getDayM());
    mvprintw(col/2,row/2+6,"%u",clock->getMonth());
    mvprintw(col/2,row/2+9,"%u",clock->getYear());
    attroff(COLOR_PAIR(5));
    refresh();
    //getch();
}