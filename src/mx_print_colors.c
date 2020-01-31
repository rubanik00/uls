#include "uls_header.h"

void mx_print_colors(char *name, char type) {
        if (type == 'd') {
            mx_printstr(LS_COLOR_BLUE);
            mx_printstr(name);
            mx_printstr(LS_COLOR_RESET);
        } 
        else if (type == 'x') {
            mx_printstr(LS_COLOR_RED);
            mx_printstr(name);
            mx_printstr(LS_COLOR_RESET);
        } 
        else
            mx_printstr(name);
}
