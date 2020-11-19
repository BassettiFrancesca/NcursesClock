#ifndef NCURSESCLOCK_TIMER_H
#define NCURSESCLOCK_TIMER_H

#include "Time24.h"
#include <ncurses.h>
#include <ctime>

class Timer {
public:
    explicit Timer(Clock* c) {
        printer = new Time24(c);
    }
    void getInput();
    void stopAt();

private:
    Time24* printer;
    int h, m, s;
};

#endif //NCURSESCLOCK_TIMER_H
