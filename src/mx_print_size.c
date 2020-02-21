#include "uls.h"

static void print_spaces(int size) {
    for(int i = 0; i <= size; i++) {
        mx_printchar(' ');
    }
}

static void print_duo_cases(t_li *print, t_sz *size) {
    char *major = mx_get_major(print);
    char *minor = mx_get_minor(print);
    
    if (size->is_dev == true)
        if (MX_IS_BLK(print->info.st_mode) || MX_IS_CHR(print->info.st_mode)) {
            print_spaces(2 - mx_strlen(major));
            mx_printstr(major);
            mx_printchar(',');
            mx_printchar(' ');
            print_spaces(2 - mx_strlen(minor));
            mx_printstr(minor); 
        }
        else {
            mx_printstr("       ");
            mx_printint(print->info.st_size);
        }
    else
       mx_printint(print->info.st_size); 
    free(major);
    free(minor);
}

void mx_print_sz(t_li *print, t_sz *size) {
    char *res_now = mx_itoa(print->info.st_size);
    char *res_sz = mx_itoa(size->sz);
    int counter = 0;

    if (mx_strlen(res_now) == mx_strlen(res_sz))
        print_duo_cases(print, size);
    else if (mx_strlen(res_now) < mx_strlen(res_sz)) {
        counter = mx_strlen(res_now);
        while (counter != mx_strlen(res_sz)) {
            mx_printchar(' ');
            counter++;
        }
        print_duo_cases(print, size);
    }
    mx_printchar(' ');
    free(res_now);
    free(res_sz);
}
