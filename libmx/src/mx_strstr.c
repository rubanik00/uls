#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int len = mx_strlen(needle);

    if (!needle) 
        return NULL;
    if (mx_strlen(haystack) < mx_strlen(needle)) 
        return NULL;
    if (!mx_strlen(needle)) 
        return (char *)haystack;
    for (; (haystack = mx_strchr(haystack, needle[0])) != NULL; haystack++) {
        if (mx_strncmp(haystack, needle, len) == 0) {
            return (char *) haystack;
        }
    }
    return NULL;
}
