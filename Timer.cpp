#include "Timer.h"

Timer::Timer(int inH, int inM, int inS) {
    h = inH;
    m = inM;
    s = inS;
    time_t rawtime;
    struct tm * timeinfo;
    int actualSec;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    actualSec = timeinfo->tm_hour*3600 + timeinfo->tm_min*60 + timeinfo->tm_sec;
    endSec = h*3600 + m*60 + s + actualSec;
}

bool Timer::updateTimer() {
    bool changed = false;
    time_t rawtime;
    struct tm * timeinfo;
    int actualSec, diffSec;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    actualSec = timeinfo->tm_hour*3600 + timeinfo->tm_min*60 + timeinfo->tm_sec;
    if(endSec > actualSec) {
        diffSec = endSec - actualSec;
        h = diffSec / 3600;
        m = (diffSec % 3600) / 60;
        s = (diffSec % 3600) % 60;
        changed = true;
    }
    return changed;
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


