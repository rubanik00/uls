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


#define LS_COLOR_RED        "\x1b[31m"
#define LS_COLOR_RESET      "\x1b[0m"

#define MX_IS_EXEC(mode) ((mode) & S_IXUSR)

typedef struct general {
    char **d_str;
}   st_general;


// Open DIR + parser
void mx_opendir(int argc, char **argv);
void mx_uls_no_flags(int argc, char *argv[]);
void mx_flag_parse(char *argv[]);
char **mx_folder_serch(int argc, char *argv[]);
void mx_print_folder_search(st_general *gnr);
//
// smal L flag
void mx_ls_l(int argc, char *dirname, char **file_name);
void *mx_getUserName(struct stat fileStat);
void *mx_getGroupName(struct stat fileStat);
void mx_edit_time(struct stat fileStat, char *t);
char mx_check_per(struct stat fileStat);
void mx_print_per(struct stat fileStat);
//
// Big R flag
void mx_ls_big_r(char **file_name);
//
// Sort flags
int mx_custom_bubble_sort(char **temp, int f(char*, char*));
int mx_cmp_t(char *s1, char *s2);
int mx_cmp_S(char *s1, char *s2);
int mx_cmp_r(char *s1, char *s2);
int mx_cmp_u(char *s1, char *s2);
int mx_cmp_c(char *s1, char *s2);
//
// smal G flag
void mx_ls_g(int argc, char *dirname, char **file_name);
//
// Big G flag
void mx_big_g(int argc, char *dirname, char **temp);
//

#endif
