#include "Date.h"

int Date::showDay() {
    string dayW;
    if (clock->getDayW() == 1) {
        dayW = "Monday";
    }
    if (clock->getDayW() == 2) {
        dayW = "Tuesday";
    }
    if (clock->getDayW() == 3) {
        dayW = "Wednesday";
    }
    if (clock->getDayW() == 4) {
        dayW = "Thursday";
    }
    if (clock->getDayW() == 5) {
        dayW = "Friday";
    }
    if (clock->getDayW() == 6) {
        dayW = "Saturday";
    }
    if (clock->getDayW() == 0) {
        dayW = "Sunday";
    }
    mvprintw(y/2, x/4, "%s", dayW.c_str());
    refresh();
    return dayW.length();
}

Clock *Date::getClock() const {
    return clock;
}

void Date::setClock(Clock *clock) {
    Date::clock = clock;
}
