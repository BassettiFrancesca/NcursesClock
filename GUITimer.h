#ifndef NCURSESCLOCK_GUITIMER_H
#define NCURSESCLOCK_GUITIMER_H

#include "Timer.h"
#include <ncurses.h>
#include <ctime>
#include <string>
using namespace std;

class GUITimer {
public:
    GUITimer() {
        getInput();
    }

    void getInput();

    void print();

private:
    Timer* timer;
};

#endif //NCURSESCLOCK_GUITIMER_H
