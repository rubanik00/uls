#include "uls.h"

bool mx_check_device(t_li **names, t_sz *size) {
    for (int i = 0; names[i]; i++) {
        if (MX_IS_BLK(names[i]->info.st_mode) || MX_IS_CHR(names[i]->info.st_mode)) {
            return size->is_dev = true;
        }
    }
    return size->is_dev = false;
}
