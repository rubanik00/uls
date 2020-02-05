        #include "uls_header.h"

const char *mx_getUserName() {
    uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);

    if (pw)
        return pw->pw_name;
    return "";
}

void *mx_getGroupName(struct stat fileStat) {
    struct group *grp = getgrgid(fileStat.st_gid);

    if (grp)
        return mx_strdup(grp->gr_name);
    else
        return mx_itoa(fileStat.st_gid);
}

void mx_edit_time(struct stat fileStat, char *t) {
    if (1564876800 >= fileStat.st_mtime) {
        for(int i = 4; i < 10; i++)
            mx_printchar(t[i]);
        mx_printchar(' ');
        for (int i = 20; i < 24; i++) {
           mx_printchar(t[i]); 
        }
    }
    else {
        for(int i = 4; i < 16; i++)
            mx_printchar(t[i]);
    }
}

char mx_check_per(struct stat fileStat) {
    if (S_ISDIR(fileStat.st_mode))
        return 'd';
    if (S_ISLNK(fileStat.st_mode))
        return 'l';
    if (S_ISBLK(fileStat.st_mode))
        return 'b';
    if (S_ISCHR(fileStat.st_mode))
        return 'c';
    if (S_ISFIFO(fileStat.st_mode))
        return 'p';
    if (S_ISSOCK(fileStat.st_mode))
        return 's';
    if (S_ISWHT(fileStat.st_mode))
        return 'w';
    return '-';
}

// static void mx_check_max(struct stat fileStat, char **file_name) {
//     int tmp = 0;
//     int i = 0;
//     while (file_name[i]) {
//         if (tmp < fileStat.st_nlink) {
//             tmp = fileStat.st_nlink;
//         }
//         i++;
//     }
//     mx_printint(tmp);
//     // mx_printchar('\n');
// }

// static void mx_print_spaces(struct stat fileStat, char **file_name) {
//     mx_check_max(fileStat, file_name);
//     mx_printchar(' ');
// }

void mx_print_per(struct stat fileStat) {

    mx_printchar(mx_check_per(fileStat));
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

// static void print_for_l(struct stat fileStat, char **file_name, int i) {

//     mx_printint(fileStat.st_nlink);
//     mx_printstr(mx_getUserName());
//     mx_printstr(mx_getGroupName(fileStat));
//     mx_printint(fileStat.st_size);
//     mx_edit_time(fileStat, ctime(&fileStat.st_mtime)); 
//     mx_printstr(file_name[i]);
//     mx_printchar('\n'); ///////////////
// }

void mx_ls_l(int argc, char *dirname, char **file_name) {
    struct stat fileStat;
    char *tmp = NULL;
    char *res = NULL;
    int lnk = 0;
    int i = 0;
    int blk_size = 0;

    while (file_name[i]) {
        if (argc > 2) {
            tmp = mx_strjoin(dirname, "/");
            res = mx_strjoin(tmp, file_name[i]);
            lstat(res, &fileStat);
        }
        else {
            lstat(file_name[i], &fileStat);
        }
        blk_size += fileStat.st_blocks;
        i++;
    }
    mx_printstr("total ");
    mx_printint(blk_size);
    mx_printstr("\n");
    i = 0; 
    for (i = 0; file_name[i]; i++) {  
        if (argc > 2) {
            tmp = mx_strjoin(dirname, "/");
            res = mx_strjoin(tmp, file_name[i]);
            lstat(res, &fileStat);
        }
        else {
            lstat(file_name[i], &fileStat);
        }
        // print ALL -l

        mx_print_per(fileStat);

        // START link //
        if (lnk < fileStat.st_nlink) {
            lnk = fileStat.st_nlink;
        }
        if (mx_strlen(mx_itoa(fileStat.st_nlink)) == mx_strlen(mx_itoa(lnk))){
            mx_printint(fileStat.st_nlink);
        }
        else if (mx_strlen(mx_itoa(fileStat.st_nlink)) < mx_strlen(mx_itoa(lnk))) {
            int counter = mx_strlen(mx_itoa(fileStat.st_nlink));
            while (counter != mx_strlen(mx_itoa(lnk))) {
                mx_printstr(" ");
                counter++;
            }
            mx_printint(fileStat.st_nlink);
        }
        mx_printstr("\n");
        // END link //

        // print_for_l(fileStat, file_name, i);
    }
}
