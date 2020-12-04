#ifndef NCURSESCLOCK_TIME12_H
#define NCURSESCLOCK_TIME12_H

#include "Time.h"
#include <ncurses.h>

class Time12 : public Time { // classe per stampare l'ora in formato 12h (AM/PM)
public:
    explicit Time12(int y, int x);

    virtual void print() override;

    virtual void updateClock() override;

    bool isAm() const;

private:
    bool AM;
};

#endif //NCURSESCLOCK_TIME12_H
