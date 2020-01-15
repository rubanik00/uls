#ifndef ULS_HEADER_H
#define ULS_HEADER_H

#include "libmx.h"
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <sys/ioctl.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <dirent.h>

typedef struct general {
    char **d_str;
}   st_general;

#endif
