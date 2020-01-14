#include "libmx.h"

void mx_intdel(int **num) {
    free(*num);
}
