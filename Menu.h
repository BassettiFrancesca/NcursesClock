#ifndef NCURSESCLOCK_MENU_H
#define NCURSESCLOCK_MENU_H

#include "GUIClock.h"
#include "GUITimer.h"
#include "Time12.h"
#include "Time24.h"
#include "DateNum.h"
#include "DateText.h"

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
