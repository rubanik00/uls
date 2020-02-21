#include "uls.h"

static char *minor_to_hex(char *minor) {
    char *hex_minor = mx_strdup("0x00000000");

    mx_strcpy(hex_minor + (10 - mx_strlen(minor)), minor);
    mx_strdel(&minor);
    return hex_minor;
}

char *mx_get_minor(t_li *print) {
    int minor_num = (int)(print->info.st_rdev & 0xffffff);
    char *minor = NULL;

    if (minor_num > 255)
        minor = minor_to_hex(mx_nbr_to_hex(minor_num));
    else
        minor = mx_itoa(minor_num);
    return minor;
}

char *mx_get_major(t_li *print) {
    return mx_itoa((int)(((unsigned int)print->info.st_rdev >> 24) & 0xff));
}
