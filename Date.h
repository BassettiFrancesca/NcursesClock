#ifndef NCURSESCLOCK_DATE_H
#define NCURSESCLOCK_DATE_H

#include "Clock.h"

class Date {
public:
    explicit Date(Clock* c) : clock(c) {}
    virtual void print() = 0;
    void updateClock(){
        Clock* newClock = new Clock();
        clock = newClock;
    }
protected:
    Clock* clock;
};

#endif //NCURSESCLOCK_DATE_H
