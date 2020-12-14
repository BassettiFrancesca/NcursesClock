#ifndef NCURSESCLOCK_DATENUMGETTER_H
#define NCURSESCLOCK_DATENUMGETTER_H

#include "DateGetter.h"

class DateNumGetter : public DateGetter { // classe per gestire la data in formato numerico (dddd dd/mm/yyyy)
public:
    DateNumGetter() : DateGetter() {}

    virtual string getStringDate() override;
};

#endif //NCURSESCLOCK_DATENUMGETTER_H
