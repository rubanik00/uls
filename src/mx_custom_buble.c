#include "uls_header.h"

int mx_custom_bubble_sort(char **temp, int f(char*, char*)) {
    char *buf = NULL;
    int count = 0;

    while (temp[count])
        count++;
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (f(temp[j], temp[j + 1]) > 0) {
                buf = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = buf;
            }
        }
    }
    
    mx_print_strarr(temp, "\n");
    return 0;
}
