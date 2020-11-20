#ifndef NCURSESCLOCK_TIME_H
#define NCURSESCLOCK_TIME_H

#include "Clock.h"

class Time {
public:
    explicit Time() {
        clock = new Clock();
    }

    Clock *getClock() const {
        return clock;
    }

    void setClock(Clock *clock) {
        Time::clock = clock;
    }

    virtual void print() = 0;

    void updateClock() {
        Clock* newClock = new Clock();
        clock = newClock;
    }

protected:
    Clock* clock;
};

#endif //NCURSESCLOCK_TIME_H
