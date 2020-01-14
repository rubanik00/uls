#include "libmx.h"

void mx_del_strarr(char ***arr) {
    char **dst = *arr;

    while (*dst)
        mx_strdel(dst++);
    free(*arr);
    *arr = NULL;
}
