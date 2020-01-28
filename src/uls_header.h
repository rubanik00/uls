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

typedef struct flag_l {
    char *total;        // Тотал в начале ls -l
    int total_count;    // Размер всех файлов
    char *permission;   // Уровень доступа +
    int links;          // Количество ссылок на файл +
    char *owner_name;   // Имя владельца 
    char *group_name;   // Имя группы
    int file_weight;    // Вес файла (в байтах) +
    char *month;        // Месяц
    int date;           // Число
    int time;           // Время
    char *file_name;    // Имя файла
}   st_flag_l;

void mx_print_folder_search(st_general *gnr);
void mx_uls_no_flags(int argc, char *argv[]);
char **mx_folder_serch(int argc, char *argv[]);
void mx_opendir(int argc, char **argv);
void mx_flag_parse(char *argv[]);
void mx_ls_l(int argc, char *dirname, char **file_name);
void mx_ls_big_r(char **file_name);
int mx_cmp_t(char *s1, char *s2);
int mx_custom_bubble_sort(char **temp, int f(char*, char*));
int mx_cmp_S(char *s1, char *s2);
int mx_cmp_r(char *s1, char *s2);
int mx_cmp_u(char *s1, char *s2);
int mx_cmp_c(char *s1, char *s2);

#endif
