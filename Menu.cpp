#include "Menu.h"

void Menu::getUserChoice() { // permette all'utente di selezionare la modalità d'uso
    int y, x;
    int selected = 0;
    int choice;
    string choices[5] = {"Clock 12h and textual date", "Clock 12h and numerical date",
                         "Clock 24h and textual date", "Clock 24h and numerical date", "Timer"};
    initscr();
    raw();
    noecho();
    curs_set(FALSE);
    keypad(stdscr,true);
    attron(A_BOLD);
    bool windowSmall = false;
    getmaxyx(stdscr, y, x);
    if(y < (y/4 + 12) || x < (x/4 + 56)) // controlla le dimensioni della finestra in uso
        windowSmall = true;
    while(windowSmall){
        getmaxyx(stdscr, y, x);
        windowSmall = resizeWindow(y, x);
    }
    while(true){
        clear();
        getmaxyx(stdscr, y, x);
        attroff(A_BOLD);
        mvprintw(y/4 - 2, x/4, "Choose by pressing key UP or DOWN and then ENTER:");
        attron(A_BOLD);
        for(int i=0; i < 5; i++){
            if(i == selected)
                attron(A_REVERSE); // evidenzia l'opzione selezionata al momento
            mvprintw(y/4 + i, x/4, "%s", choices[i].c_str());
            attroff(A_REVERSE);
            refresh();
        }
        choice = getch();
        while(choice != KEY_UP && choice != KEY_DOWN && choice != 10){ // se l'utente non ha premuto le frecce o invio
            mvprintw(y/4 + 7, x/2, "WRONG KEY");
            refresh();
            choice = getch();
        }
        if(choice == KEY_UP){
            selected--;
            if(selected == -1)
                selected = 4; // menù circolare
        }
        if(choice == KEY_DOWN){
            selected++;
            if(selected == 5){
                selected = 0; // menù circolare
            }
        }
        if(choice == 10){ // se è stato premuto invio
            clear();
            refresh();
            break;
        }
    }
    printChoice(selected);
}

void Menu::printChoice(int choice) { // stampa la scelta selezionata
    if(choice == 0){
        Time12Getter* time = new Time12Getter();
        DateTextGetter* date = new DateTextGetter();
        clock = new GUIClock(date, time);
        while(true){
            clock->print();
        }
    }
    if(choice == 1){
        Time12Getter* time = new Time12Getter();
        DateNumGetter* date = new DateNumGetter();
        clock = new GUIClock(date, time);
        while(true){
            clock->print();
        }
    }
    if(choice == 2){
        Time24Getter* time = new Time24Getter();
        DateTextGetter* date = new DateTextGetter();
        clock = new GUIClock(date, time);
        while(true){
            clock->print();
        }
    }
    if(choice == 3){
        Time24Getter* time = new Time24Getter();
        DateNumGetter* date = new DateNumGetter();
        clock = new GUIClock(date, time);
        while(true){
            clock->print();
        }
    }
    if(choice == 4){
        timer = new GUITimer;
        timer->print();
    }
}

bool Menu::resizeWindow(int y, int x) { // gestisce il caso in cui la finestra aperta dall'utente sia troppo piccola
    if(y >= (y/4 + 12) && x >= (x/4 + 56))
        return false;
    else printw("RESIZE WINDOW PLEASE (this message will be shown until right dimension)");
    refresh();
    getch();
    clear();
    return true;
}
