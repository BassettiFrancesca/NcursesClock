#include "DateGetter.h"

string DateGetter::getStringDayWeek() {
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

    return dayW;
}

Clock *DateGetter::getClock() const {
    return clock;
}

void DateGetter::setClock(Clock *newClock) {
    DateGetter::clock = newClock;
}
