#include "uls_header.h"

int mx_cmp_t(char *s1, char *s2) {
    struct stat fileStat1;
    struct stat fileStat2;

    lstat(s1, &fileStat1);
    lstat(s2, &fileStat2);

    if (fileStat1.st_mtime > fileStat2.st_mtime) {
        return 1;
    }
    return 0;
}
