#include "libmx.h"

static int res(const char *str, int i,int sign) {
    int result = 0;

    while (str[++i])
        if (mx_isdigit(str[i]))
            result = result * 10 + str[i] - '0';
        if (!mx_isdigit(str[i]))
            return result * sign;
    return result;
}

int mx_atoi(const char *str) {
    int result = 0;
    int i = -1;
    int sign = 1;

    while (str[++i]) {
        if (!mx_isspace(str[i])) {
            if (str[i] == '-') {
                sign = - 1;
                break;
            }
            else if (str[i] == '+')
                break;
            i--;
            break;
        }
    }
    result = res(str, i, sign);
    return result * sign;
}
