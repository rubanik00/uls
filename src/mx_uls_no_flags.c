#include "uls_header.h"

void mx_uls_no_flags(int argc, char *argv[]) {
    st_general *gnr = (st_general*)malloc(sizeof(st_general));

	if (argc == 1)
		mx_opendir();
	if (argc > 1) {
		if (argv[1][0] != '-') {
			gnr->d_str = mx_folder_serch(argc, argv);
			mx_print_folder_search(gnr);
		}
		else if (argv[1][0] == '-' && argv[1][1]) {
			mx_printchar('1');
		}
		else {
			mx_printerr("uls: ");
            mx_printerr(argv[1]);
            mx_printerr_exit(": No such file or directory\n");
		}
	}
}
