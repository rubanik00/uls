#include "uls_header.h"

static void print_opendir(int count, char **temp) {
    for (int i = 2; i < count; ++i) {
        mx_printstr(temp[i]);
    	mx_printstr("\t");
    }
    mx_printchar('\n');
}

void mx_opendir() {
    int count = 0;
    DIR *dptr;
    struct dirent *ds;
    char **temp;

    dptr = opendir(".");
    while ((ds = readdir(dptr)) != NULL)
    	count++;
    closedir(dptr);
    dptr = opendir(".");
    temp = (char**)malloc(sizeof(char) * count);
    for (int i = 0; (ds = readdir(dptr)) != NULL; i++) {
        temp[i] = malloc(sizeof(char*) * mx_strlen(ds->d_name));
        temp[i] = ds->d_name;
        temp[i + 1] = NULL;
    }
    closedir(dptr);
    print_opendir(count, temp);
}
