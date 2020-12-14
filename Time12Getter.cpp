#include "Time12Getter.h"

Time12Getter::Time12Getter() : TimeGetter() { // il costruttore trasforma in formato 12h
    int hour = clock->getHour(); // prende l'ora in formato 24h
    if (hour == 12){ // se è mezzogiorno -> 12 PM
        AM = false;
    }
    if (hour == 0){ // se è mezzanotte -> 12 AM
        hour = 12;
        AM = true;
        clock->setHour(hour);
    }
    if (hour > 12){ // se l'ora è da 13-23
        hour -= 12;
        AM = false;
        clock->setHour(hour);
    }
    else AM = true; // se l'ora è da 1-11
}

string Time12Getter::getStringTime() {
    updateClock(); // si aggiorna all'ora attuale
    int h, m, s;
    h = clock->getHour();
    m = clock->getMinutes();
    s = clock->getSeconds();
    string hour, minutes, seconds;
    if( h <= 9 ){
        hour = "0" + to_string(h);
    } else { hour = to_string(h); }
    if( m <= 9 ){
        minutes = "0" + to_string(m);
    } else { minutes = to_string(m); }
    if( s <= 9 ){
        seconds = "0" + to_string(s);
    } else { seconds = to_string(s); }
    string AMorPM;
    if (AM){
        AMorPM = "AM";
    } else { AMorPM = "PM"; }
    string time = hour + ":" + minutes + ":" + seconds + " " + AMorPM;
    return time;
}

void Time12Getter::updateClock() {
    TimeGetter::updateClock();
    int hour = clock->getHour();
    if (hour == 12){
        AM = false;
    }
    if (hour == 0){
        hour = 12;
        AM = true;
        clock->setHour(hour);
    }
    if (hour > 12){
        hour -= 12;
        AM = false;
        clock->setHour(hour);
    }
    else AM = true;
}

bool Time12Getter::isAm() const {
    return AM;
}
