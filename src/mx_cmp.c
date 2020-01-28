#include "uls_header.h"

int mx_cmp_c(char *s1, char *s2) {
    struct stat fileStat1;
    struct stat fileStat2;

    lstat(s1, &fileStat1);
    lstat(s2, &fileStat2);
    
    // ls -tc
    if (fileStat1.st_ctime < fileStat2.st_ctime) {
        return 1;   
    }
    return 0;

    // Join to mx_custom_bubble_sort
    //
    // struct stat fileStat;
    // for (int i = 0; temp[i]; i++) {
    //     lstat(temp[i], &fileStat);
    //     mx_printstr(ctime(&fileStat.st_ctime));
    // }
}

int mx_cmp_u(char *s1, char *s2) {
    struct stat fileStat1;
    struct stat fileStat2;

    lstat(s1, &fileStat1);
    lstat(s2, &fileStat2);
    
    // ls -ut
    if (fileStat1.st_atime < fileStat2.st_atime) {
        return 1;   
    }
    return 0;

    // Join to mx_custom_bubble_sort
    //
    // struct stat fileStat;
    // for (int i = 0; temp[i]; i++) {
    //     lstat(temp[i], &fileStat);
    //     mx_printstr(ctime(&fileStat.st_atime));
    // }
    // mx_print_strarr(temp, "\n");
}

int mx_cmp_r(char *s1, char *s2) {

    if (s1 || s2) {
        return 1;
    }
    return 0;   
}

int mx_cmp_S(char *s1, char *s2) {
    struct stat fileStat1;
    struct stat fileStat2;

    lstat(s1, &fileStat1);
    lstat(s2, &fileStat2);

    if (fileStat1.st_size < fileStat2.st_size) {
        return 1;
    }
    return 0;
}

int mx_cmp_t(char *s1, char *s2) {
    struct stat fileStat1;
    struct stat fileStat2;

    lstat(s1, &fileStat1);
    lstat(s2, &fileStat2);

    if (fileStat1.st_mtime < fileStat2.st_mtime) {
        return 1;
    }
    return 0;
}
