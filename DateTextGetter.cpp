#include "DateTextGetter.h"

string DateTextGetter::getStringDate() {
    updateClock();
    string date = getStringDayWeek() + " " + to_string(clock->getDayM()) + " " + getStringMonth() + " " +
                                                       to_string(clock->getYear());
    return date;
}

string DateTextGetter::getStringMonth() {
    string month;

    if (clock->getMonth() == 1) {
        month = "January";
    }
    if (clock->getMonth() == 2) {
        month = "February";
    }
    if (clock->getMonth() == 3) {
        month = "March";
    }
    if (clock->getMonth() == 4) {
        month = "April";
    }
    if (clock->getMonth() == 5) {
        month = "May";
    }
    if (clock->getMonth() == 6) {
        month = "June";
    }
    if (clock->getMonth() == 7) {
        month = "July";
    }
    if (clock->getMonth() == 8) {
        month = "August";
    }
    if (clock->getMonth() == 9) {
        month = "September";
    }
    if (clock->getMonth() == 10) {
        month = "October";
    }
    if (clock->getMonth() == 11) {
        month = "November";
    }
    if (clock->getMonth() == 12) {
        month = "December";
    }

    return month;
}