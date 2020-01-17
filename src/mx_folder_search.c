#include "uls_header.h"

char **mx_folder_serch(int argc, char *argv[]) {
    DIR *dptr;
    struct dirent *ds;
    char **temp = (char**)malloc(sizeof(char) * 100000);
    int count = 0;

    for (int i = 1; i < argc; i++) {
        dptr = opendir(argv[i]);
        if (dptr == NULL) {
            mx_printerr("uls: ");
            mx_printerr(argv[i]);
            mx_printerr_exit(": No such file or directory\n");
        }
        while((ds = readdir(dptr)) != 0) {
            temp[count] = malloc(sizeof(char*) * mx_strlen(ds->d_name));
            temp[count] = ds->d_name;
            count++;
        }
    }
    closedir(dptr);
    return temp;
}
