#include "uls_header.h"

void print_usage() {
    mx_printerr_exit("usage: uls [-l] [file ...]\n");
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
    for (int i = 0; i < 7; ++i) {
        if (temp[i][0] == '.') {
            i++;
        }
        mx_printstr(temp[i]);
    	mx_printstr("\t");
    }
    mx_printchar('\n');
}

int main(int argc, char *argv[]) {
    //st_general *gnr = (st_general*)malloc(sizeof(st_general));
    
    if (argc == 1) {
        mx_opendir();
    }
    mx_printstr(argv[0]);
}
