#ifndef NCURSESCLOCK_DATEGETTER_H
#define NCURSESCLOCK_DATEGETTER_H

#include "Clock.h"
#include <string>
using namespace std;

class DateGetter {
public:
    DateGetter() {
        clock = new Clock();
    }

    Clock *getClock() const;

    void setClock(Clock *newClock);

    virtual string getStringDate() = 0;

    void updateClock() {
        delete clock;
        clock = new Clock();
    }

    virtual ~DateGetter() {}

    string getStringDayWeek();

protected:
    Clock* clock;
};

#endif //NCURSESCLOCK_DATEGETTER_H
