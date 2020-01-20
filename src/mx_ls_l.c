#include "uls_header.h"

const char *getUserName() {
  uid_t uid = geteuid();
  struct passwd *pw = getpwuid(uid);
  
  if (pw) {
    return pw->pw_name;
  }

  return "";
}

void *getGroupName(char *argv) {
  struct stat info;
  lstat(argv, &info);
  struct group *grp = getgrgid(info.st_gid);

  if (grp)
    return mx_strdup(grp->gr_name);
  else
  {
    return mx_itoa(info.st_gid);
  }
  
}

int mx_ls_l(char *argv) {
    struct stat fileStat;

    if(stat(argv,&fileStat) < 0)    
        return 1;
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

    mx_printchar('\t');

    mx_printstr(getUserName());
    mx_printchar('\t');
    mx_printstr(getGroupName(argv));
    mx_printchar('\t');
    mx_printint(fileStat.st_nlink);
    mx_printchar('\t');
    mx_printint(fileStat.st_size);
    mx_printchar('\t');
    mx_printstr(argv);
    mx_printchar('\n');
    return 0;
}
