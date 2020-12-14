#ifndef NCURSESCLOCK_GUICLOCK_H
#define NCURSESCLOCK_GUICLOCK_H

#include "Date.h"
#include "Time.h"

class GUIClock {
public:
    GUIClock(Date* d,Time* t) : datePrinter(d), timePrinter(t) {}

    void print() {
        datePrinter->print();
        timePrinter->print();
    }


    // TODO: cambiare responsabilità qui ncurses gli altri solo rendere le stringhe
private:
    Date* datePrinter;
    Time* timePrinter;
};

#endif //NCURSESCLOCK_GUICLOCK_H
