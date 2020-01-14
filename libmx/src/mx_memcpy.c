#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned const char *s = src;
    unsigned char *d = dst;

    while(n--) 
        *d++ = *s++;
    return dst;
}
