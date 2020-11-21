#ifndef NCURSESCLOCK_TIME12_H
#define NCURSESCLOCK_TIME12_H

#include "Time.h"
#include <ncurses.h>

class Time12 : public Time {
public:
    explicit Time12(int y, int x);

    virtual void print() override;

    virtual void updateClock() override;

private:
    bool AM;
};

#endif //NCURSESCLOCK_TIME12_H
