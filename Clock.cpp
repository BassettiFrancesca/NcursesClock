#include "Clock.h"

void Clock::setDate() {
    dayM = timeinfo->tm_mday; // giorni del mese da 1-31
    dayW = timeinfo->tm_wday; // giorni della settimana da 0-6 (giorni passati dalla domenica)
    month = timeinfo -> tm_mon + 1; // perché erano da 0-11 in ctime
    year = timeinfo->tm_year + 1900; // perché sono gli anni passati dal 1900
}

void Clock::setTime() {
    hour = timeinfo->tm_hour;
    minutes = timeinfo->tm_min;
    seconds = timeinfo->tm_sec;
}

int Clock::getDayW() const {
    return dayW;
}

void Clock::setDayW(int dayW) {
    if ( dayW >= 0 && dayW <= 6)
        Clock::dayW = dayW;
}

int Clock::getMonth() const {
    return month;
}

void Clock::setMonth(int month) {
    if ( month >= 1 && month <= 12 )
        Clock::month = month;
}

int Clock::getYear() const {
    return year;
}

void Clock::setYear(int year) {
    Clock::year = year;
}

int Clock::getDayM() const {
    return dayM;
}

void Clock::setDayM(int dayM) {
    if ((year%400==0 || (year%4==0 && year%100!=0)) && month == 2){ // gestione anni bisestili
        if (dayM <= 29 && dayM >= 1)
            Clock::dayM = dayM;
    }
    else if (month == 2) { // febbraio
        if (dayM <= 28 && dayM >= 1)
            Clock::dayM = dayM;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) { // mesi di 30 giorni
        if (dayM <= 30 && dayM >= 1)
            Clock::dayM = dayM;
    }
    else if (dayM <= 31 && dayM >= 1)
        Clock::dayM = dayM;
}

int Clock::getHour() const {
    return hour;
}

void Clock::setHour(int hour) {
    if ( hour >= 0 && hour < 24 )
        Clock::hour = hour;
}

int Clock::getMinutes() const {
    return minutes;
}

void Clock::setMinutes(int minutes) {
    if ( minutes < 60 && minutes >= 0)
        Clock::minutes = minutes;
}

int Clock::getSeconds() const {
    return seconds;
}

void Clock::setSeconds(int seconds) {
    if ( seconds < 60 && seconds >= 0)
        Clock::seconds = seconds;
}

bool Clock::operator==(const Clock* right) const {
    if (hour == right->getHour() && minutes == right->getMinutes() && seconds == right->getSeconds()) {
        if (dayW == right->getDayW() && dayM == right->getDayM() && month == right->getMonth() &&
            year == right->getYear())
            return true;
    }
    return false;
}
