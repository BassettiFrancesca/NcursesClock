#include "GUITimer.h"

void GUITimer::getInput() { // fa selezionare la durata del timer
    int y,x; // altezza e larghezza finestra
    int selected;
    int input;
    int chosen[3]; // per ricordarsi che ore, minuti e secondi sono stati selezionati
    int max[3] = {23, 59, 59}; // massimo per ore - minuti - secondi
    string choices[3] = {"hours", "minutes", "seconds"};
    for(int i = 0;i < 3;i++) {
        selected = 0;
        getmaxyx(stdscr, y, x);
        clear();
        mvprintw(y / 2 - 3, x / 4, "Select how many %s should pass by", choices[i].c_str());
        mvprintw(y / 2 - 2, x / 4, "pressing key UP or DOWN and then ENTER");
        attroff(A_BOLD);
        mvprintw(y / 2, x / 2, "%d", selected);
        attron(A_BOLD);
        refresh();
        while (true) {
            getmaxyx(stdscr, y, x);
            input = getch();
            while (input != KEY_UP && input != KEY_DOWN && input != 10) { // se l'utente non usa le frecce o invio
                mvprintw(y / 2 + 2, x / 2 - 4, "WRONG KEY");
                refresh();
                input = getch();
            }
            if (input == KEY_UP) { // se ha premuto la freccia su aumenta il valore selezionato fino al massimo
                if (selected < max[i]) {
                    selected++;
                    clear();
                    mvprintw(y / 2 - 3, x / 4, "Select how many %s should pass by", choices[i].c_str());
                    mvprintw(y / 2 - 2, x / 4, "pressing key UP or DOWN and then ENTER");
                    attroff(A_BOLD);
                    mvprintw(y / 2, x / 2, "%d", selected);
                    attron(A_BOLD);
                    refresh();
                }
            }
            if (input == KEY_DOWN) { // se ha premuto la freccia giù diminuisce il valore selezionato fino a 0
                if (selected > 0) {
                    selected--;
                    clear();
                    mvprintw(y / 2 - 3, x / 4, "Select how many %s should pass by", choices[i].c_str());
                    mvprintw(y / 2 - 2, x / 4, "pressing key UP or DOWN and then ENTER");
                    attroff(A_BOLD);
                    mvprintw(y / 2, x / 2, "%d", selected);
                    attron(A_BOLD);
                    refresh();
                }
            }
            if (input == 10) { // se viene premuto invio
                break;
            }
        }
        chosen[i] = selected;
    }
    timer = new Timer(chosen[0], chosen[1], chosen[2]); // si crea il timer con i valori selezionati
    clear();
    refresh();
}

void GUITimer::print() { // stampa il tempo rimanente del timer
    clear();
    refresh();
    int y,x;
    getmaxyx(stdscr,y,x);
    bool changed = timer->updateTimer();
    while(changed){ // continua finché non ha finito il tempo
        refresh();
        changed = timer->updateTimer(); // aggiorna il timer
        int h,m,s;
        h = timer->getH();
        m = timer->getM();
        s = timer->getS();
        if(h>9){ // stampa il tempo rimanente con eventuali 0 davanti se cifra tra 0-9
            if(m>9){
                if(s>9){
                    mvprintw(y/2,x/2 - 4,"%d:%d:%d",h,m,s);
                }
                else{
                    mvprintw(y/2,x/2 - 4,"%d:%d:0%d",h,m,s);
                }
            }
            else{
                if(s>9){
                    mvprintw(y/2,x/2 - 4,"%d:0%d:%d",h,m,s);
                }
                else{
                    mvprintw(y/2,x/2 - 4,"%d:0%d:0%d",h,m,s);
                }
            }
        }
        else{
            if(m>9){
                if(s>9){
                    mvprintw(y/2,x/2 - 4,"0%d:%d:%d",h,m,s);
                }
                else{
                    mvprintw(y/2,x/2 - 4,"0%d:%d:0%d",h,m,s);
                }
            }
            else{
                if(s>9){
                    mvprintw(y/2,x/2 - 4,"0%d:0%d:%d",h,m,s);
                }
                else{
                    mvprintw(y/2,x/2 - 4,"0%d:0%d:0%d",h,m,s);
                }
            }
        }
    }
    clear();
    attron(A_BLINK);
    mvprintw(y/2 - 1,x/2 - 5,"TIME IS UP!"); // informa che il tempo è scaduto
    attroff(A_BLINK);
    attroff(A_BOLD);
    mvprintw(y/2 + 1,x/2 - 10,"press any key to exit"); // istruisce su come uscire dal programma
    refresh();
    getch();
    endwin();
}

