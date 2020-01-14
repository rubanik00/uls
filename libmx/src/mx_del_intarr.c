#include "libmx.h"

void mx_del_intarr(int ***num_arr) {
    int **dst = *num_arr;

    while (*dst)
        mx_intdel(dst++);
    free(*num_arr);
}
