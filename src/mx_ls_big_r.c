#include "uls_header.h"

static char **l_r_parse(char *dirname) {
    DIR *dptr;
    struct dirent *ds;
    int count = 0;
    char **temp = NULL;
    int j = 0;
    
    dptr = opendir(dirname);
    while ((ds = readdir(dptr)) != NULL) {
        if (ds->d_name[0] != '.')
        count++;
    }
    closedir(dptr);
    dptr = opendir(dirname);
    temp = (char**)malloc(sizeof(char *) * (count + 1));
    for (j = 0; (ds = readdir(dptr));) {
        if (ds->d_name[0] != '.') {
            temp[j] = mx_strdup(ds->d_name);
            temp[j + 1] = NULL;
            j++;
        }
    }
    closedir(dptr);
    return temp;
}

void mx_ls_big_r(char **fileName) {
    struct stat fileStat;

    // mx_print_strarr(fileName, " ");
    for (int i = 0; fileName[i]; i++) {
        lstat(fileName[i], &fileStat);
        if (S_ISDIR(fileStat.st_mode)) {
            mx_printstr("./");
            mx_printstr(fileName[i]);
            mx_printstr(":\n");
            char **tmp = l_r_parse(fileName[i]);
            mx_print_strarr(tmp, "\t");
        }
    }
}
