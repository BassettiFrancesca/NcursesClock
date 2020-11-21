#include "Time24.h"

void Time24::print() {
    updateClock();
    int y,x,h,m,s;
    h = clock->getHour();
    m = clock->getMinutes();
    s = clock->getSeconds();
    getmaxyx(stdscr,y,x);
    if(h>9){
        if(m>9){
            if(s>9){
                mvprintw(y/4,x/2,"%d:%d:%d",h,m,s);
            }
            else{
                mvprintw(y/4,x/2,"%d:%d:0%d",h,m,s);
            }
        }
        else{
            if(s>9){
                mvprintw(y/4,x/2,"%d:0%d:%d",h,m,s);
            }
            else{
                mvprintw(y/4,x/2,"%d:0%d:0%d",h,m,s);
            }
        }
    }
    else{
        if(m>9){
            if(s>9){
                mvprintw(y/4,x/2,"0%d:%d:%d",h,m,s);
            }
            else{
                mvprintw(y/4,x/2,"0%d:%d:0%d",h,m,s);
            }
        }
        else{
            if(s>9){
                mvprintw(y/4,x/2,"0%d:0%d:%d",h,m,s);
            }
            else{
                mvprintw(y/4,x/2,"0%d:0%d:0%d",h,m,s);
            }
        }
    }
}