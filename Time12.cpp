#include "Time12.h"

Time12::Time12(int y, int x) : Time(y,x) { // il costruttore trasforma in formato 12h
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

void Time12::print() {
    updateClock(); // si aggiorna all'ora attuale
    int h, m, s;
    h = clock->getHour();
    m = clock->getMinutes();
    s = clock->getSeconds();
    if(h>9){ // stampa l'ora con eventuali 0 davanti se cifra tra 0-9
        if(m>9){
            if(s>9){
                mvprintw(y/4,x/4,"%d:%d:%d",h,m,s);
            }
            else{
                mvprintw(y/4,x/4,"%d:%d:0%d",h,m,s);
            }
        }
        else{
            if(s>9){
                mvprintw(y/4,x/4,"%d:0%d:%d",h,m,s);
            }
            else{
                mvprintw(y/4,x/4,"%d:0%d:0%d",h,m,s);
            }
        }
    }
    else{
        if(m>9){
            if(s>9){
                mvprintw(y/4,x/4,"0%d:%d:%d",h,m,s);
            }
            else{
                mvprintw(y/4,x/4,"0%d:%d:0%d",h,m,s);
            }
        }
        else{
            if(s>9){
                mvprintw(y/4,x/4,"0%d:0%d:%d",h,m,s);
            }
            else{
                mvprintw(y/4,x/4,"0%d:0%d:0%d",h,m,s);
            }
        }
    }
    if (AM)
        mvprintw(y/4,x/4 + 9,"AM");
    else
        mvprintw(y/4,x/4 + 9,"PM");
    refresh();
}

void Time12::updateClock() {
    Time::updateClock();
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

bool Time12::isAm() const {
    return AM;
}
