#ifndef NCURSESCLOCK_TIME_H
#define NCURSESCLOCK_TIME_H

#include "Clock.h"

class Time {
public:
    explicit Time(Clock* c) : clock(c) {}
    virtual void print() = 0;
    void updateClock(){
        Clock* newClock = new Clock();
        clock = newClock;
    }
protected:
    Clock* clock;
};

#endif //NCURSESCLOCK_TIME_H
