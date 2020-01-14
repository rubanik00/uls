#include "libmx.h"

void mx_printerr_exit(const char *s) {
    write(2, s, mx_strlen(s));
    exit(EXIT_FAILURE);
}
