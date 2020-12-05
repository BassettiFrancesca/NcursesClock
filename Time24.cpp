#include "Time24.h"

void Time24::print() {
    updateClock(); // si aggiorna all'ora attuale
    int h, m, s;
    h = clock->getHour();
    m = clock->getMinutes();
    s = clock->getSeconds();
    if(h>9){ // stampa l'ora con eventuali 0 davanti se cifra tra 0-9
        if(m>9){
            if(s>9){
                mvprintw(y/4,x/4,"%d:%d:%d",h,m,s);
            }
            else{
                mvprintw(y/4,x/4,"%d:%d:0%d",h,m,s);
            }
        }
        else{
            if(s>9){
                mvprintw(y/4,x/4,"%d:0%d:%d",h,m,s);
            }
            else{
                mvprintw(y/4,x/4,"%d:0%d:0%d",h,m,s);
            }
        }
    }
    else{
        if(m>9){
            if(s>9){
                mvprintw(y/4,x/4,"0%d:%d:%d",h,m,s);
            }
            else{
                mvprintw(y/4,x/4,"0%d:%d:0%d",h,m,s);
            }
        }
        else{
            if(s>9){
                mvprintw(y/4,x/4,"0%d:0%d:%d",h,m,s);
            }
            else{
                mvprintw(y/4,x/4,"0%d:0%d:0%d",h,m,s);
            }
        }
    }
    refresh();
}