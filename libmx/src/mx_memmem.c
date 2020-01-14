#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
     const char *str = big;
     const char *need = little;

    if (big_len < little_len || big_len == 0 ||little_len == 0)
        return NULL;
    if (!mx_strlen(little)) 
        return NULL;
    if (mx_strstr(str, need)) 
        return mx_strstr(str, need);
    return NULL;
}
