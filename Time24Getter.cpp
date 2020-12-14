#include "Time24Getter.h"

string Time24Getter::getStringTime() {
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
    string time = hour + ":" + minutes + ":" + seconds;
    return time;
}