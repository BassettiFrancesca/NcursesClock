#include "DateText.h"

void DateText::print() {
    updateClock();
    int l = showDay() + 1; // lunghezza della stringa del giorno e uno spazio
    mvprintw(y/2,x/4 + l,"%d",clock->getDayM());
    int m = showMonth(l) + l + 1; // lunghezza di quello stampato prima e uno spazio
    mvprintw(y/2,x/4 + m,"%d",clock->getYear());
    refresh();
}

int DateText::showMonth(int l) {
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
    int d = 2; // se il giorno del mese è da 1 a 9
    if(clock->getDayM() > 9) // se è di due cifre per spazio nel testo
        d = 3;
    mvprintw(y/2, x/4 + l + d, "%s", month.c_str());
    refresh();
    return month.length() + d;
}