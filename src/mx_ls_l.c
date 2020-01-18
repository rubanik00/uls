#include "uls_header.h"

int mx_ls_l(char *argv) {
    struct stat fileStat;

    if(stat(argv,&fileStat) < 0)    
        return 1;
    printf("File Size: \t\t%lld bytes\n",fileStat.st_size);
    printf("Number of Links: \t%d\n",fileStat.st_nlink);
    printf("File inode: \t\t%llu\n",fileStat.st_ino);
    // printf("%ld.",fileStat.st_atimespec);
    // mx_printstr("\n");
    mx_printint(fileStat.st_blksize);
    mx_printstr("\n");
    mx_printint(fileStat.st_blocks);
    mx_printstr("\n");
    mx_printint(fileStat.st_dev);
    mx_printstr("\n");
    mx_printint(fileStat.st_flags);
    mx_printstr("\n");
    mx_printint(fileStat.st_gen);
    mx_printstr("\n");
    printf("%s",fileStat.st_birthtimespec);
    mx_printstr("\n");
    mx_printint(fileStat.st_mode);
    mx_printstr("\n");
    //mx_printint(fileStat.st_qspare);
    mx_printstr("\n");
    mx_printint(fileStat.st_rdev);
    mx_printstr("\n");
    mx_printint(fileStat.st_uid);
    mx_printstr("\n");
    mx_printstr("\n");
    printf("File Permissions: \t");
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");
    return 0;
}
