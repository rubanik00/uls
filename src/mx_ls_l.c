#include "uls_header.h"

static const char *getUserName() {
    uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);

    if (pw)
        return pw->pw_name;
    return "";
}

static void *getGroupName(struct stat fileStat) {
    struct group *grp = getgrgid(fileStat.st_gid);

    if (grp)
        return mx_strdup(grp->gr_name);
    else
        return mx_itoa(fileStat.st_gid);
}

static void edit_time(char *t) {
    for(int i = 4; i < 16; i++)
        mx_printchar(t[i]);
}

static void print_per(struct stat fileStat) {

    mx_printstr( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    mx_printstr( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    mx_printstr( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    mx_printstr( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    mx_printstr( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    mx_printstr( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    mx_printstr( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    mx_printstr( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    mx_printstr( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    mx_printstr( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    mx_printstr("  ");
}

static void print_other(struct stat fileStat, char **file_name, int i) {

    mx_printint(fileStat.st_nlink);
    mx_printstr(" ");
    mx_printstr(getUserName());
    mx_printstr("  ");
    mx_printstr(getGroupName(fileStat));
    mx_printstr("  ");
    mx_printint(fileStat.st_size);
    mx_printstr(" ");
    edit_time(ctime(&fileStat.st_mtime)); 
    mx_printstr("\t");
    mx_printstr(file_name[i]);
    mx_printstr("\n");
}

void mx_ls_l(int argc, char *dirname, char **file_name) {
    struct stat fileStat;
    int i = 0;
    char *tmp = NULL;
    char *res = NULL;

    while(file_name[i]) {  
        if (argc > 2) {
            tmp = mx_strjoin(dirname, "/");
            res = mx_strjoin(tmp, file_name[i]);
            lstat(res, &fileStat);
        }
        else {
            lstat(file_name[i], &fileStat);
        }
        print_per(fileStat);
        print_other(fileStat, file_name, i);
        i++;
    }
}
