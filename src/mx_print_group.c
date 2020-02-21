#include "uls.h"

void mx_get_user_name(t_li *print, int usr) {
    struct passwd *pw = getpwuid(print->info.st_uid);
    int counter = 0;
    char *name = NULL;

    if (pw)
        name = mx_strdup(pw->pw_name);
    else
        name = mx_itoa(print->info.st_uid);
    if (mx_strlen(name) == usr)
       mx_printstr(name);
    else if (mx_strlen(name) < usr) {
        counter = mx_strlen(name);
        mx_printstr(name);
        while (counter != usr) {
            mx_printchar(' ');
            counter++;
        }
    }
    mx_printstr("  ");
    free(name);
}

void mx_get_group_name(t_li *print, int group) {
    struct group *grp = getgrgid(print->info.st_gid);
    int counter = 0;
    char *name = NULL;

    if (grp)
        name = mx_strdup(grp->gr_name);
    else
        name = mx_itoa(print->info.st_gid);
    if (mx_strlen(name) == group)
        mx_printstr(name);
    else if (mx_strlen(name) < group) {
        counter = mx_strlen(name);
        mx_printstr(name);
        while (counter != group) {
            mx_printchar(' ');
            counter++;
        }
    }
    mx_printstr("  ");
    free(name);
}
