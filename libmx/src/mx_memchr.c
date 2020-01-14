#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char c1 = c;
    unsigned const char *tmp = s;

    while (*tmp && n--) {
        if (*tmp == c1) 
            return (char*)tmp;
        tmp++;
    }
    return NULL;
}
