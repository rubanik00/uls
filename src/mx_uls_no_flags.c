#include "uls_header.h"

void mx_uls_no_flags(int argc, char *argv[]) {
    st_general *gnr = (st_general*)malloc(sizeof(st_general));

	if (argc == 1)
		mx_opendir();
	if (argc > 1) {
		gnr->d_str = mx_folder_serch(argc, argv);
		mx_print_folder_search(gnr);
	}
}
