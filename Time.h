#ifndef NCURSESCLOCK_TIME_H
#define NCURSESCLOCK_TIME_H

#include "Clock.h"

class Time {
public:
    explicit Time(int iY, int iX) {
        clock = new Clock();
        y = iY; // altezza della finestra in cui è eseguito il programma
        x = iX; // larghezza della finestra in cui è eseguito il programma
    }

    Clock *getClock() const {
        return clock;
    }

    void setClock(Clock *clock) {
        Time::clock = clock;
    }

    virtual void print() = 0;

    virtual void updateClock() {
        delete clock;
        clock = new Clock();
    }

    virtual ~Time() {}

protected:
    Clock* clock;
    int y, x;
};

#endif //NCURSESCLOCK_TIME_H
