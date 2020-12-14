#ifndef NCURSESCLOCK_GUICLOCK_H
#define NCURSESCLOCK_GUICLOCK_H

#include "DateGetter.h"
#include "TimeGetter.h"
#include <ncurses.h>

class GUIClock {
public:
    GUIClock(DateGetter* d, TimeGetter* t) : dateGetter(d), timeGetter(t) {
        getmaxyx(stdscr, y, x);
    }

    void print();

private:
    DateGetter* dateGetter;
    TimeGetter* timeGetter;
    int y, x;
};

#endif //NCURSESCLOCK_GUICLOCK_H
