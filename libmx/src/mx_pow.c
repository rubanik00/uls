#include "libmx.h"

double mx_pow(double n, int pow) {
    if (pow == 0)
        return 1;
    else if (pow == 1)
        return n;
    else 
        return n * mx_pow (n,pow - 1);
}
