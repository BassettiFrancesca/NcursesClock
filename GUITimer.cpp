#include "GUITimer.h"

void GUITimer::getInput() {
    int y,x;
    getmaxyx(stdscr,y,x);
    int selected = 0;
    int h, m, s;
    clear();
    mvprintw(y/2,x/2,"Select how many hours should pass");
    //fare menu a tendina per ore minuti secondi (ENTER = 10)
    timer = new Timer(h, m, s);
    clear();
}

void GUITimer::print() {
    int y,x;
    getmaxyx(stdscr,y,x);
    bool changed = timer->updateTimer();
    while(changed){
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
        refresh();
    }
    clear();
    attron(A_BLINK);
    mvprintw(y/2,x/2,"TIME IS UP!");
    attron(A_BLINK);
    mvprintw(y/2 + 2,x/2,"press any key to exit");
    attroff(A_BOLD);
    getch();
    endwin();
}

