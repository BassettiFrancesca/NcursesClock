#ifndef NCURSESCLOCK_TIME24_H
#define NCURSESCLOCK_TIME24_H

#include "Time.h"
#include <ncurses.h>

class Time24 : public Time {
public:
    explicit Time24(Clock* c) : Time(c) {}
    virtual void print() override;
};

#endif //NCURSESCLOCK_TIME24_H
