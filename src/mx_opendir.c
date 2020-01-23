#include "uls_header.h"

// static void print_opendir(char **temp, int argc, char *argv[], int n) {
//     int i = 0;

//     if (isatty(1)) {
//         if (argc > 2) {
//             mx_printstr(argv[n]);
//             mx_printstr(":\n");
//         }
//         //mx_printDir(&(*temp));
//         for (i = 0; temp[i + 1]; i++) {
//             mx_printstr(temp[i]);
//         	mx_printstr("\t");
//         }
//         mx_printstr(temp[i]);
//         mx_printchar('\n');
//         if (argc > 2 && n != argc - 1) {
//             mx_printchar('\n');
//         }
//     }
//     else {
//         if (argc > 2) {
//             mx_printstr(argv[n]);
//             mx_printstr(":\n");
//         }
//         for (i = 0; temp[i]; i++) {
//             mx_printstr(temp[i]);
//             mx_printstr("\n");
//         }
//         if (argc > 2 && n != argc - 1)
//             mx_printchar('\n');
//         // mx_del_strarr(&temp);
//     }
// }


void mx_opendir(int argc, char *argv[]) {
    int count = 0;
    DIR *dptr;
    struct dirent *ds;
    char **temp = NULL;
    int i = 1;
    char **arg = argv+1;
    int size = 2;

    if (argc > 3) {
	    while (arg[size])
	    	size++;
	    mx_bubble_sort(arg, size);
	}


    if (argc != 2 && argc != 1)
        i = 2;
    for (; i < argc; i++, count = 0) {
        if (argc == 2)
            dptr = opendir(".");
        else
            dptr = opendir(argv[i]);
        while ((ds = readdir(dptr)) != NULL) {
            if (ds->d_name[0] != '.')
                count++;
        }
        closedir(dptr);
        if (argc == 2)
            dptr = opendir(".");
        else
            dptr = opendir(argv[i]);
        temp = (char**)malloc(sizeof(char *) * (count + 1));
        for (int j = 0; (ds = readdir(dptr));) {
            if (ds->d_name[0] != '.') {
                temp[j] = mx_strdup(ds->d_name);
                temp[j + 1] = NULL;
                j++;
            }
        }
        closedir(dptr);
        size = 0;
        while(temp[size])
        	size++;
        mx_bubble_sort(temp, size);
        if (argc > 3) {
            mx_printstr(argv[i]);
            mx_printstr(":\ntotal 0\n");
        }
        // mx_ls_l(argc, argv[i], temp);
        mx_ls_big_r(temp);
        if (argc > 3 && i != argc - 1)
            mx_printchar('\n');
        // print_opendir(temp, argc, argv, i);
        // mx_del_strarr(&temp);
    }
}
