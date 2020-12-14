#include "gtest/gtest.h"

#include "../Timer.h"


TEST(Timer, IsChanged) {
    Timer* t = new Timer(1, 1, 1);
    bool changed = t->updateTimer();
    ASSERT_TRUE(changed); // controllo che il timer sia aggiornato
}


TEST(Timer, RightTimePassed) {
    Timer* t = new Timer(0, 0, 5);
    bool changed = true;
    time_t startTime, endTime;
    time(&startTime);
    while(changed){
        changed = t->updateTimer();
    }
    time(&endTime);
    ASSERT_LE(difftime(endTime, startTime), 6);
}