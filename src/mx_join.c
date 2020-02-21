#include "uls.h"

int mx_max_len_n_g(t_li **names) {
    int max = 0;
    int temp = 0;

    for (int i = 0; names[i]; i++) {
        temp = mx_strlen(names[i]->name);
        if (temp > max)
            max = temp;
    }
    max++;
    return max;
}

void mx_print_spaces_g(int len, int maxlen) {
    int count = 0;

    count = maxlen - len;
    for (int i = 0; i < count; i++)
        mx_printchar(' ');
}

void mx_nulloutput(st_fl **fl) {
    (*fl)->x = 0;
    (*fl)->l = 0;
    (*fl)->C = 0;
    (*fl)->m = 0;
    (*fl)->force = 0;
}

void mx_err_flag(st_fl **fl, char flag) {
    mx_printerr("uls: illegal option -- ");
    mx_printcharerr(flag);
    mx_printerr("\n");
    mx_printerr("usage: uls [-ACGRSTcfglmortux1] [file ...]\n");
    free(*fl);
    fl = NULL;
    exit(1);
}

void mx_join(char **res, char *s2) {
    char *newstr = mx_strnew(mx_strlen(*res) + mx_strlen(s2));
    int i = 0;
    int si = -1;
    char *s1 = *res;

    while(s1[++si]) {
        newstr[i] = s1[si];
        i++;
    }
    si = -1;
    while(s2[++si]) {
        newstr[i] = s2[si];
        i++;
    }
    mx_strdel(&(*res));
    *res = newstr;
}
