#ifndef NCURSESCLOCK_DATE_H
#define NCURSESCLOCK_DATE_H

#include "Clock.h"
#include <ncurses.h>
#include <string>
using namespace std;

class Date {
public:
    explicit Date(int iY, int iX) {
        clock = new Clock();
        y = iY; // altezza della finestra in cui è eseguito il programma
        x = iX; // larghezza della finestra in cui è eseguito il programma
    }

    Clock *getClock() const;

    void setClock(Clock *newClock);

    virtual void print() = 0;

    void updateClock() {
        delete clock;
        clock = new Clock();
    }

    int showDay();

protected:
    Clock* clock;
    int y, x;
};

#endif //NCURSESCLOCK_DATE_H
