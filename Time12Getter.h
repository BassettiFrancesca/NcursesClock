#ifndef NCURSESCLOCK_TIME12GETTER_H
#define NCURSESCLOCK_TIME12GETTER_H

#include "TimeGetter.h"
#include <string>
using namespace std;

class Time12Getter : public TimeGetter { // classe per gestire l'ora in formato 12h (AM/PM)
public:
    Time12Getter();

    virtual string getStringTime() override;

    virtual void updateClock() override;

    bool isAm() const;

private:
    bool AM;
};

#endif //NCURSESCLOCK_TIME12GETTER_H
