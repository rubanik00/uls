#include "uls.h"

void mx_edit_time(t_li *print, char *t, st_fl *fl) {
    int i = 0;

    if (fl->T == 1)
        for (i = 4; i < t[i]; i++)
           mx_printchar(t[i]); 
    else {
        if (1565913600 >= print->info.st_mtime) {
            for(i = 4; i < 10; i++)
                mx_printchar(t[i]);
            mx_printstr("  ");
            for (i = 20; i < 24; i++)
                mx_printchar(t[i]); 
        }
        else
            for(i = 4; i < 16; i++)
                mx_printchar(t[i]);
    }
    mx_printstr(" ");
}
