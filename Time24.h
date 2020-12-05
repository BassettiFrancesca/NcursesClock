#ifndef NCURSESCLOCK_TIME24_H
#define NCURSESCLOCK_TIME24_H

#include "Time.h"
#include <ncurses.h>

class Time24 : public Time { // classe per stampare l'ora in formato 24h
public:
    explicit Time24(int y, int x) : Time(y,x) {}

    virtual void print() override;
};

#endif //NCURSESCLOCK_TIME24_H
