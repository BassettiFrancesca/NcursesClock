#include "gtest/gtest.h"

#include "../Timer.h"

TEST(Timer, IsChanged) {
    Timer* t = new Timer(1, 1, 1);
    bool changed = t->updateTimer();
    ASSERT_TRUE(changed);
}