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
    int y, x;
    getmaxyx(stdscr, y, x);
    if(choice == 0){
        Time12* time = new Time12(y,x);
        DateText* date = new DateText(y,x);
        clock = new GUIClock(date, time);
        while(true){
            clock->print();
        }
    }
    if(choice == 1){
        Time12* time = new Time12(y,x);
        DateNum* date = new DateNum(y,x);
        clock = new GUIClock(date, time);
        while(true){
            clock->print();
        }
    }
    if(choice == 2){
        Time24* time = new Time24(y,x);
        DateText* date = new DateText(y,x);
        clock = new GUIClock(date, time);
        while(true){
            clock->print();
        }
    }
    if(choice == 3){
        Time24* time = new Time24(y,x);
        DateNum* date = new DateNum(y,x);
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
