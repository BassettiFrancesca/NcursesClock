#ifndef NCURSESCLOCK_DATENUM_H
#define NCURSESCLOCK_DATENUM_H

#include "Date.h"
#include <ncurses.h>

class DateNum : public Date {
public:
    explicit DateNum(Clock* c) : Date(c) {}
    virtual void print() override;
};

#endif //NCURSESCLOCK_DATENUM_H
