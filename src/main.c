#include "uls_header.h"

void print_usage() {
    mx_printerr_exit("usage: uls [-l] [file ...]\n");
}

int main(int argc, char *argv[]) {
    mx_uls_no_flags(argc, argv);
    // system("leaks -q uls");
}
