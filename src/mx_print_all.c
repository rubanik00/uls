#include "uls.h"

static void print_link_and_color(t_li *print, st_fl *fl) {
    if (fl->G == 1)
        mx_printstr_g(print);
    else if (MX_IS_LNK(print->info.st_mode)) {
        mx_printstr(print->name);
        mx_print_symblink(print);
    }
    else
        mx_printstr(print->name);
}

void mx_print_all(t_li *print, t_sz *size, st_fl *fl) {
    time_t *chtime = &print->info.st_ctime;
    time_t *atime = &print->info.st_atime;
    time_t *t = &print->info.st_mtime;

    mx_print_per(print);
    mx_print_lnk(print, size);
    if ((fl->l == 1 && fl->g == 0) || (fl->o == 1 && fl->g == 0))
        mx_get_user_name(print, size->usr);
    if ((fl->l == 1 && fl->o == 0) || (fl->g == 1 && fl->o == 0))
        mx_get_group_name(print, size->group);
    mx_print_sz(print, size);
    if (fl->u == 1)
        t = atime;
    if (fl->c == 1)
        t = chtime;
    mx_edit_time(print, ctime(t), fl);
    print_link_and_color(print, fl);
    mx_printchar('\n');
}
