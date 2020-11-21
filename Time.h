#ifndef NCURSESCLOCK_TIME_H
#define NCURSESCLOCK_TIME_H

#include "Clock.h"

class Time {
public:
    explicit Time(int iY, int iX) {
        clock = new Clock();
        y = iY;
        x = iX;
    }

    Clock *getClock() const {
        return clock;
    }

    void setClock(Clock *clock) {
        Time::clock = clock;
    }

    virtual void print() = 0;

    virtual void updateClock() {
        Clock* newClock = new Clock();
        clock = newClock;
    }

protected:
    Clock* clock;
    int y, x;
};

#endif //NCURSESCLOCK_TIME_H
