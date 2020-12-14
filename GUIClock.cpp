#include "GUIClock.h"

void GUIClock::print() {
    mvprintw(y/4, x/4, "%s", timeGetter->getStringTime().c_str());
    mvprintw(y/2, x/4, "%s", dateGetter->getStringDate().c_str());
    refresh();
}
