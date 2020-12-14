#ifndef NCURSESCLOCK_TIMEGETTER_H
#define NCURSESCLOCK_TIMEGETTER_H

#include "Clock.h"
#include <string>
using namespace std;

class TimeGetter {
public:
    TimeGetter() {
        clock = new Clock();
    }

    Clock *getClock() const {
        return clock;
    }

    void setClock(Clock *clock) {
        TimeGetter::clock = clock;
    }

    virtual string getStringTime() = 0;

    virtual void updateClock() {
        delete clock;
        clock = new Clock();
    }

    virtual ~TimeGetter() {}

protected:
    Clock* clock;
};

#endif //NCURSESCLOCK_TIMEGETTER_H
