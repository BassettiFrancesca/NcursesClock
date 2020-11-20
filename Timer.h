#ifndef NCURSESCLOCK_TIMER_H
#define NCURSESCLOCK_TIMER_H

#include <ctime>

class Timer {
public:
    Timer(int inH, int inM, int inS);

    bool updateTimer();

    int getH() const;

    int getM() const;

    int getS() const;

private:
    int h, m, s, endSec;
};


#endif //NCURSESCLOCK_TIMER_H
