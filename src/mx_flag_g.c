#include "uls_header.h"

static void print_for_g(struct stat fileStat, char **file_name, int i) {

    mx_printint(fileStat.st_nlink);
    mx_printstr(" ");
    mx_printstr(mx_getGroupName(fileStat));
    mx_printstr("  ");
    mx_printint(fileStat.st_size);
    mx_printstr(" ");
    mx_edit_time(ctime(&fileStat.st_mtime)); 
    mx_printstr("\t");
    mx_printstr(file_name[i]);
    mx_printstr("\n");
}

void mx_ls_g(int argc, char *dirname, char **file_name) {
    struct stat fileStat;
    int i = 0;
    char *tmp = NULL;
    char *res = NULL;
    int blk_size = 0;

    while (file_name[i]) {
        if (argc > 2) {
            tmp = mx_strjoin(dirname, "/");
            res = mx_strjoin(tmp, file_name[i]);
            lstat(res, &fileStat);
        }
        else {
            lstat(file_name[i], &fileStat);
        }
        blk_size += fileStat.st_blocks;
        i++;
    }
    mx_printstr("total ");
    mx_printint(blk_size);
    mx_printstr("\n");
    i = 0;
    while(file_name[i]) {  
        if (argc > 2) {
            tmp = mx_strjoin(dirname, "/");
            res = mx_strjoin(tmp, file_name[i]);
            lstat(res, &fileStat);
        }
        else {
            lstat(file_name[i], &fileStat);
        }
        mx_print_per(fileStat);
        print_for_g(fileStat, file_name, i);
        i++;
    }
}
