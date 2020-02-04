#include "uls_header.h"

void mx_big_g(int argc, char *dirname, char **temp) {
    struct stat fileStat;
    char *tmp = NULL;
    char *res = NULL;
    int i = 0;

    while (temp[i]) {
        if (argc > 2) {
            tmp = mx_strjoin(dirname, "/");
            res = mx_strjoin(tmp, temp[i]);
            lstat(res, &fileStat);
        }
        else {
            lstat(temp[i], &fileStat);
        }
        
        // ****************** //
        if (S_ISDIR(fileStat.st_mode)) {
            mx_printstr("\033[34m");
            mx_printstr(temp[i]);
            mx_printstr(LS_COLOR_RESET);
        }
        else if (S_ISLNK(fileStat.st_mode)) {
            mx_printstr("\033[35m");
            mx_printstr(temp[i]);
            mx_printstr(LS_COLOR_RESET);
        }
        else if (fileStat.st_mode & S_IXOTH) {
            mx_printstr(LS_COLOR_RED);
            mx_printstr(temp[i]);
            mx_printstr(LS_COLOR_RESET);
        }
        else if (S_ISBLK(fileStat.st_mode)) {
            mx_printstr("\033[34;46m");
            mx_printstr(temp[i]);
            mx_printstr(LS_COLOR_RESET);
        }
        else if (S_ISCHR(fileStat.st_mode)) {
            mx_printstr("\033[34;43m");
            mx_printstr(temp[i]);
            mx_printstr(LS_COLOR_RESET);
        }
        else if (S_ISSOCK(fileStat.st_mode)) {
            mx_printstr("\033[32m");
            mx_printstr(temp[i]);
            mx_printstr(LS_COLOR_RESET);
        }
        else if (S_ISFIFO(fileStat.st_mode)) {
            mx_printstr("\033[33m");
            mx_printstr(temp[i]);
            mx_printstr(LS_COLOR_RESET);
        }
        else if (S_ISWHT(fileStat.st_mode)) {
            mx_printstr("\033[36m");
            mx_printstr(temp[i]);
            mx_printstr(LS_COLOR_RESET);
        }
        else if (MX_IS_EXEC(fileStat.st_mode)) {
            mx_printstr("\033[31m");
            mx_printstr(temp[i]);
            mx_printstr(LS_COLOR_RESET);
        }
        else
            mx_printstr(temp[i]);
        
        mx_printstr("\n");
        i++;
    }
}
