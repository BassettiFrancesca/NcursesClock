#include "Timer.h"

Timer::Timer(int inH, int inM, int inS) {
    h = inH;
    m = inM;
    s = inS; // memorizza i valori inseriti dall'utente
    time_t rawtime;
    struct tm * timeinfo;
    int actualSec;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    actualSec = timeinfo->tm_hour*3600 + timeinfo->tm_min*60 + timeinfo->tm_sec; // calcola l'ora attuale in secondi
    endSec = h*3600 + m*60 + s + actualSec; // calcola l'ora finale in secondi
}

bool Timer::updateTimer() {
    bool changed = false;
    time_t rawtime;
    struct tm * timeinfo;
    int actualSec, diffSec;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    actualSec = timeinfo->tm_hour*3600 + timeinfo->tm_min*60 + timeinfo->tm_sec; // calcola l'ora attuale in secondi
    if(endSec > actualSec) { // se non ha ancora raggiunto l'ora finale aggiorna il timer
        diffSec = endSec - actualSec; // calcola la differenza tra l'ora finale e la attuale
        h = diffSec / 3600;
        m = (diffSec % 3600) / 60;
        s = (diffSec % 3600) % 60;
        changed = true;
    }
    return changed; // variabile che rimane vera finché il timer non scade
}

int Timer::getH() const {
    return h;
}

int Timer::getM() const {
    return m;
}

int Timer::getS() const {
    return s;
}


