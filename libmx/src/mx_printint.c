#include "libmx.h"

void mx_printint(int n) {
    if (n == -2147483648){
        mx_printchar('-');
        mx_printint(214748364);
        mx_printchar('8');
    }
    else {
        if (n < 0) {
            n *= -1;
            mx_printchar('-');
        }
        if (n > 9) {
            mx_printint(n/10);
            mx_printchar((n%10)+48);	
        }
        if (n <= 9) 
            mx_printchar(n+48);
    }
}
