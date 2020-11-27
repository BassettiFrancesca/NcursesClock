#include "GUITimer.h"

void GUITimer::getInput() {
    int y,x;
    int selected;
    int input;
    int chosen[3];
    int max[3] = {23, 59, 59};
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
            while (input != KEY_UP && input != KEY_DOWN && input != 10) {
                mvprintw(y / 2 + 2, x / 2 - 4, "WRONG KEY");
                refresh();
                input = getch();
            }
            if (input == KEY_UP) {
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
            if (input == KEY_DOWN) {
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
            if (input == 10) {
                break;
            }
        }
        chosen[i] = selected;
    }
    timer = new Timer(chosen[0], chosen[1], chosen[2]);
    clear();
    refresh();
}

void GUITimer::print() {
    clear();
    refresh();
    int y,x;
    getmaxyx(stdscr,y,x);
    bool changed = timer->updateTimer();
    while(changed){
        refresh();
        changed = timer->updateTimer();
        int h,m,s;
        h = timer->getH();
        m = timer->getM();
        s = timer->getS();
        if(h>9){
            if(m>9){
                if(s>9){
                    mvprintw(y/2,x/2,"%d:%d:%d",h,m,s);
                }
                else{
                    mvprintw(y/2,x/2,"%d:%d:0%d",h,m,s);
                }
            }
            else{
                if(s>9){
                    mvprintw(y/2,x/2,"%d:0%d:%d",h,m,s);
                }
                else{
                    mvprintw(y/2,x/2,"%d:0%d:0%d",h,m,s);
                }
            }
        }
        else{
            if(m>9){
                if(s>9){
                    mvprintw(y/2,x/2,"0%d:%d:%d",h,m,s);
                }
                else{
                    mvprintw(y/2,x/2,"0%d:%d:0%d",h,m,s);
                }
            }
            else{
                if(s>9){
                    mvprintw(y/2,x/2,"0%d:0%d:%d",h,m,s);
                }
                else{
                    mvprintw(y/2,x/2,"0%d:0%d:0%d",h,m,s);
                }
            }
        }
    }
    clear();
    attron(A_BLINK);
    mvprintw(y/2 - 1,x/2 - 5,"TIME IS UP!");
    attroff(A_BLINK);
    attroff(A_BOLD);
    mvprintw(y/2 + 1,x/2 - 10,"press any key to exit");
    refresh();
    getch();
    endwin();
}

