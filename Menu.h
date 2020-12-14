#ifndef NCURSESCLOCK_MENU_H
#define NCURSESCLOCK_MENU_H

#include "GUIClock.h"
#include "GUITimer.h"
#include "Time12Getter.h"
#include "Time24Getter.h"
#include "DateNumGetter.h"
#include "DateTextGetter.h"

class Menu {
public:
    Menu(){
        getUserChoice();
    }

    void getUserChoice();

    void printChoice(int choice);

    bool resizeWindow(int y, int x);

private:
    GUIClock* clock;
    GUITimer* timer;
};

#endif //NCURSESCLOCK_MENU_H
