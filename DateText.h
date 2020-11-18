#ifndef NCURSESCLOCK_DATETEXT_H
#define NCURSESCLOCK_DATETEXT_H

#include "Date.h"
#include <ncurses.h>

class DateText : public Date {
public:
    explicit DateText(Clock* c) : Date(c) {}
    virtual void print() override;
    void showDay();
    void showMonth();
};

#endif //NCURSESCLOCK_DATETEXT_H
