#include "uls_header.h"

void mx_flag_parse(char *argv[]) {
    switch (argv[1][1]) {
        case 'l':
            // for (int j = 0; j < count - 3; j++)
                mx_ls_l(argv[2]);
            break;
        default:
            mx_printerr_exit("usage: uls [-l] [file ...]\n");
            break;
        }
}
