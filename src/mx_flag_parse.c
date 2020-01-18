#include "uls_header.h"

static void switches1(char *argv[]) {
    switch (argv[1][1]) {
        case 'l':
            mx_ls_l(argv[2]);
            break;
        case 'a':
            mx_printchar('a');
            //mx_small_a();
            break;
        default:
            mx_printerr_exit("usage: uls [-l] [file ...]\n");
            break;
        }
}

// static void switches2(char *argv[]) {
//     switch (argv[1][2]) {
//         case 'l':
//             mx_printchar('l');
//             //mx_ls_l();
//             break;
//         case 'a':
//             mx_printchar('a');
//             //mx_small_a();
//             break;
//         default:
//             mx_printerr_exit("usage: uls [-l] [file ...]\n");
//             break;
//         }
// }

void mx_flag_parse(char *argv[]) {
    int counter = 0;
    char **dup = argv;

    for (int i = 1; dup[1][i]; i++)
        counter++;
        switches1(argv);
    // else if (counter == 2) {
    //     switches1(argv);
    //     switches2(argv);
    // }
    
}
