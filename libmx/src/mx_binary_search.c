#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int first = 0;
    int last = size - 1;
    int mid = (first + last) / 2;
    
    *count = 0;
    while (first <= last) {
        *count += 1;
        if (mx_strcmp(arr[mid], s) < 0) 
            first = mid + 1;
        else if (mx_strcmp(arr[mid], s) == 0) 
            return mid;
        else 
            last = mid - 1;
        mid = (first + last) / 2;
    }
    *count = 0;
    return -1;
}
