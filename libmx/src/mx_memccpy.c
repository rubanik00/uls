#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char *d = dst;
    unsigned const char *s = src;

    while (n > 0) {
        *d = *s;
        if (*d == c) {
            d++;
            return d;
        }
        d++;
        s++;
        n--;
    }
    return NULL;
}
