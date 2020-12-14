#include "gtest/gtest.h"

#include "../Clock.h"


class ClockSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        c.setHour(5);
        c.setMinutes(5);
        c.setSeconds(5);
        c.setDayW(5);
        c.setDayM(5);
        c.setMonth(5);
    }

    Clock c;
};


TEST_F(ClockSuite, TestSetterWrongValues) {
    c.setHour(90);
    c.setMinutes(90);
    c.setSeconds(90);
    c.setDayW(9);
    c.setDayM(33);
    c.setMonth(15); // valori che non devono essere accettati dai setter

    ASSERT_EQ(5, c.getHour());
    ASSERT_EQ(5, c.getMinutes());
    ASSERT_EQ(5, c.getSeconds());
    ASSERT_EQ(5, c.getDayW());
    ASSERT_EQ(5, c.getDayM());
    ASSERT_EQ(5, c.getMonth()); // controlli che non siano stati memorizzati valori non validi
}


TEST_F(ClockSuite, TestSetterRightValues) {
    c.setHour(15);
    c.setMinutes(30);
    c.setSeconds(25);
    c.setDayW(3);
    c.setDayM(11);
    c.setMonth(10); // valori che devono essere accettati dai setter

    ASSERT_EQ(15, c.getHour());
    ASSERT_EQ(30, c.getMinutes());
    ASSERT_EQ(25, c.getSeconds());
    ASSERT_EQ(3, c.getDayW());
    ASSERT_EQ(11, c.getDayM());
    ASSERT_EQ(10, c.getMonth()); // controlli che siano stati memorizzati i valori validi
}
