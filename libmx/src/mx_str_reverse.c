#include "libmx.h"

void mx_str_reverse(char *s) {
    int size = mx_strlen(s) - 1;
    char tmp = 0;

    for (int i = 0; i < mx_strlen(s) / 2; i++, size--) {
        tmp = s[i];
        s[i] = s[size];
        s[size] = tmp;
    }
}
