#ifndef NCURSESCLOCK_DATETEXT_H
#define NCURSESCLOCK_DATETEXT_H

#include "Date.h"
#include <ncurses.h>

class DateText : public Date { // classe per stampare la data in formato testuale (dddd dd mmmm yyyy)
public:
    explicit DateText(int y, int x) : Date(y, x) {}

    virtual void print() override;

    int showMonth(int l);
};

#endif //NCURSESCLOCK_DATETEXT_H
