#ifndef NCURSESCLOCK_DATE_H
#define NCURSESCLOCK_DATE_H

#include "Clock.h"
#include <ncurses.h>

class Date {
public:
    explicit Date(int iY, int iX) {
        clock = new Clock();
        y = iY;
        x = iX;
    }

    Clock *getClock() const;

    void setClock(Clock *clock);

    virtual void print() = 0;

    void updateClock() {
        Clock* newClock = new Clock();
        clock = newClock;
    }

    void showDay();

protected:
    Clock* clock;
    int y, x;
};

#endif //NCURSESCLOCK_DATE_H
