#include "uls_header.h"

void mx_flag_parse(char *argv[]) {
    
    switch (argv[1][1]) {
        case 'l':
            // for (int j = 0; j < count; j++)
                // mx_ls_l();
                mx_printstr(argv[1]);
            break;
        default:
            mx_printerr_exit("usage: uls [-l] [file ...]\n");
            break;
        }
}

