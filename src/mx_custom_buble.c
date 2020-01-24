#include "uls_header.h"

int mx_custom_bubble_sort(char **temp, int size, int f(char *s1, char *s2)) {
    char *buf = NULL;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++){
            if (f(temp[j], temp[j + 1]) > 0) {
                buf = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = buf;
            }
        }
    }
    mx_print_strarr(temp, " ");
    return 0;
}
