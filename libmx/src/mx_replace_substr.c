#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    int count = mx_count_substr(str, sub);
    int len = mx_strlen(str) - (mx_strlen(sub) * count)
    + (mx_strlen(replace) * count);
    char *copy_str = (char *)malloc(len * sizeof(char));
    char *copy_str2 = copy_str;

    if (!sub || !replace || !str) 
        return NULL;
    while(*str != '\0') {
        if (str != mx_strstr(str, sub)) {
            *copy_str = *str;
            str++;
            copy_str++;
        }
        if (str == mx_strstr(str, sub)) {
            mx_strncpy(copy_str, replace, mx_strlen(replace));
            copy_str += mx_strlen(replace);
            str += mx_strlen(sub);
        }
    }
    return copy_str2;
}
