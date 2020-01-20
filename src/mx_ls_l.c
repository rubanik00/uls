#include "uls_header.h"

static const char *getUserName() {
    uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);

    if (pw)
        return pw->pw_name;
    return "";
}

static void *getGroupName(char *file_name) {
    struct stat info;
    lstat(file_name, &info);
    struct group *grp = getgrgid(info.st_gid);

    if (grp)
        return mx_strdup(grp->gr_name);
    else
        return mx_itoa(info.st_gid);
}

static void edit_time(char *t) {
    for(int i = 4; i < 16; i++) {
        mx_printchar(t[i]);
    }
}

static void print_frst(struct stat fileStat) {

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

int mx_ls_l(char *file_name) {
    struct stat fileStat;

    if(stat(file_name, &fileStat) < 0)    
        return 1;
    print_frst(fileStat);
    mx_printint(fileStat.st_nlink);
    mx_printstr(" ");
    mx_printstr(getUserName());
    mx_printstr("  ");
    mx_printstr(getGroupName(file_name));
    mx_printstr("  ");
    mx_printint(fileStat.st_size);
    mx_printstr(" ");
    edit_time(ctime(&fileStat.st_mtime)); 
    mx_printstr("\t");
    mx_printstr(file_name);
    mx_printstr("\n");
    return 0;
}
