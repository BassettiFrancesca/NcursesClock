#ifndef NCURSESCLOCK_TIMER_H
#define NCURSESCLOCK_TIMER_H

#include "Clock.h"
#include <ncurses.h>
#include <ctime>

class Timer {
public:
    explicit Timer(Clock* c) : clock(c) {}
    void getInput();
    void stopAt();

private:
    Clock* clock;
    int h, m, s;
};

#endif //NCURSESCLOCK_TIMER_H
