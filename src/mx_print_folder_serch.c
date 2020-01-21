#include "uls_header.h"

// static char **clear_d_str(st_general *gnr) {
// 	char **temp = NULL;
// 	int count = 0;

// 	for (int i = 0; gnr->d_str[i]; ++i)
// 		count++;
// 	temp = (char**)malloc(sizeof(char**) * count);
// 	for (int i = 0, n = 0; gnr->d_str[i]; ++i) {
// 		temp[n] = (char*)malloc(sizeof(char*) * 200);
// 		if (mx_strcmp(gnr->d_str[i], ".") == 0) {
// 			i++;
// 		}
// 		temp[n] = gnr->d_str[i];
// 		n++;
// 	}
// 	return temp;
// }

static void b_sort(char **arr) { 
    char *buf = (char*)malloc(sizeof(char) * 200);
    int size = 0;

    while(arr[size])
    	size++;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (mx_strcmp(arr[j], arr[j + 1]) > 0) {
                buf = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buf;
             }
             
         }
     }
}

void mx_print_folder_search(st_general *gnr) {
	char **temp = gnr->d_str;
	int i = 1;

	b_sort(temp);
	if (isatty(1)) {
		for (i = 0; temp[i] && temp[i+1] != NULL; i++) {
			mx_printstr(temp[i]);
			mx_printstr("\t");
		}
		mx_printstr(temp[i]);
		mx_printchar('\n');
	}
	else {
		for (i = 0; temp[i]; i++) {
			mx_printstr(temp[i]);
			mx_printchar('\n');
		}
	}
}
