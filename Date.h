#ifndef NCURSESCLOCK_DATE_H
#define NCURSESCLOCK_DATE_H

#include "Clock.h"
#include <ncurses.h>

class Date {
public:
    explicit Date() {
        clock = new Clock();
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
};

#endif //NCURSESCLOCK_DATE_H
