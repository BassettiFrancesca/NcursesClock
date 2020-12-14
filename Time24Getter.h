#ifndef NCURSESCLOCK_TIME24GETTER_H
#define NCURSESCLOCK_TIME24GETTER_H

#include "TimeGetter.h"
#include <string>
using namespace std;

class Time24Getter : public TimeGetter { // classe per gestire l'ora in formato 24h
public:
    Time24Getter() : TimeGetter() {}

    virtual string getStringTime() override;
};

#endif //NCURSESCLOCK_TIME24GETTER_H
