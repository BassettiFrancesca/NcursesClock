#ifndef NCURSESCLOCK_DATETEXT_H
#define NCURSESCLOCK_DATETEXT_H

#include "Date.h"
#include <ncurses.h>

class DateText : public Date {
public:
    explicit DateText() : Date() {}

    virtual void print() override;

    void showMonth();
};

#endif //NCURSESCLOCK_DATETEXT_H
