#ifndef NCURSESCLOCK_DATETEXTGETTER_H
#define NCURSESCLOCK_DATETEXTGETTER_H

#include "DateGetter.h"

class DateTextGetter : public DateGetter { // classe per gestire la data in formato testuale (dddd dd mmmm yyyy)
public:
    DateTextGetter() : DateGetter() {}

    virtual string getStringDate() override;

    string getStringMonth();
};

#endif //NCURSESCLOCK_DATETEXTGETTER_H
