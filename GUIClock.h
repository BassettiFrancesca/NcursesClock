#ifndef NCURSESCLOCK_GUICLOCK_H
#define NCURSESCLOCK_GUICLOCK_H

#include "Date.h"
#include "Time.h"

class GUIClock {
public:
    GUIClock(Date* d,Time* t) : datePrinter(d), timePrinter(t) {}

    void printDate() {
        datePrinter->print();
    }

    void printTime() {
        timePrinter->print();
    }

private:
    Date* datePrinter;
    Time* timePrinter;
};

#endif //NCURSESCLOCK_GUICLOCK_H
