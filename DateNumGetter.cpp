#include "DateNumGetter.h"

string DateNumGetter::getStringDate() {
    updateClock(); // aggiorna all'ora corrente
    string date = getStringDayWeek() + " " + to_string(clock->getDayM()) + "/" + to_string(clock->getMonth())
            + "/" + to_string(clock->getYear());
    return date;
}
