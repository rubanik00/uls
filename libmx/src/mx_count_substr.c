#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int len = 0;
    int counter = 0;

    if (!str || !sub) 
        return -1;
    len = mx_strlen(sub);
    if (len == 0) 
        return 0;
    for (str = mx_strstr(str, sub); str; str = mx_strstr(str + len, sub))
        counter++;
    return counter;
}
