/*************************************************************************
	> File Name: ls_util.h
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月19日 星期三 13时48分33秒
 ************************************************************************/

#ifndef _LS_UTIL_H
#define _LS_UTIL_H

#include <stdio.h>
#include <sys/stat.h> //这个头文件用来得到文件的详细信息
#include <string.h>
#include <time.h> //时间头文件
#include <pwd.h> // 用来得到用户名
#include <grp.h> //用来得到组名

struct attribute {
    char mode[10]; //文件属性和权限
    int links; // 链接数
    char user_name[20]; //用户名
    char group_name[20]; //组名
    long size; //文件大小
    char mtime[20];
    char filename[255]; //文件名
    char extra[3]; //用来显示时候要加“×”（可执行文件）或者“/"(链接文件)
    int dit; //标记
};

int f(long n) {
    int ret = 0;
    while (n) {
        n /= 10;
        ++ret;
    }
    return ret;
}

void getTerminatorSize (int *cols, int *lines) {
    #ifdef TIOCGSIZE
    struct ttysize ts;
    ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
    *cols = ts.ts_cols;
    *lines = ts.ts_lines;
    #elif defined (TIOCGWINSZ)
    struct winsize ts;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &ts);
    *cols = ts.ws_col;
    *lines = ts.ws_row;
    #endif /* TIOCGSIZE */
}

void mode2str (int mode, char str[]) {
    strcpy(str, "----------\0");
    if (S_ISDIR(mode)) str[0] = 'd';
    if (S_ISCHR(mode)) str[0] = 'c';
    if (S_ISBLK(mode)) str[0] = 'b';
    if (S_ISLNK(mode)) str[0] = 'l';

    if (mode & S_IRUSR) str[1] = 'r';
    if (mode & S_IWUSR) str[2] = 'w';
    if (mode & S_IXUSR) str[3] = 'x';

    if (mode & S_IRGRP) str[4] = 'r';
    if (mode & S_IWGRP) str[5] = 'w';
    if (mode & S_IXGRP) str[6] = 'x';

    if (mode & S_IROTH) str[7] = 'r';
    if (mode & S_IWOTH) str[8] = 'w';
    if (mode & S_IXOTH) str[9] = 'x';
}

void uid2str (uid_t uid, char *user_name) {
    struct passwd *pw_ptr;
    pw_ptr = getpwuid(uid);

    if (pw_ptr == NULL) {
        sprintf(user_name, "%d", uid);
    } else {
        strcpy(user_name, pw_ptr->pw_name);
    }
}

void gid2str (gid_t gid, char *group_name) {
    struct group *grp_ptr;
    grp_ptr = getgrgid(gid);
    if (grp_ptr == NULL) {
        sprintf(group_name, "%d", gid);
    } else {
        strcpy(group_name, grp_ptr->gr_name);
    }
}

void time2str(time_t t, char *time_str) {
    strcpy(time_str, ctime(&t) + 4);
    time_str[12] = '\0';
}

void lsshort_type (char *dirname, char *filename, char *type) {
    char fullname[256];
    strcpy(fullname, dirname);
    strcpy(fullname + strlen(dirname), filename);

    struct stat mystat;
    if (stat(fullname, &mystat) != -1) {
        int mode = (int) mystat.st_mode;
        char str_mode[10];
        mode2str(mode, str_mode);
        if (str_mode[0] == 'd') {
            type[0] = '/';
        } else if (str_mode[0] == '-' && str_mode[3] == 'x') {
            type[0] = '*';
        }
    }
}



void ls_long_file (char *dirname, char *filename, struct attribute *file_attri) {
    char fullname[256];
    strcpy(fullname, dirname);
    strcpy(fullname + strlen(dirname), filename);

    struct stat mystat;
    if (stat(fullname, &mystat) == -1) {
        printf("ls_long_file: stat error\n");
    } else {
        int mode   = (int) mystat.st_mode;
        int links  = (int) mystat.st_nlink;
        int uid    = (int) mystat.st_uid;
        int gid    = (int) mystat.st_gid;
        long size  = (long) mystat.st_size;
        long mtime = (long) mystat.st_mtime;
        char str_mode[10];
        char str_user_name[20];
        char str_group_name[20];
        char str_mtime[20];
        mode2str(mode, str_mode);
        uid2str(uid, str_user_name);
        gid2str(gid, str_group_name);
        time2str(mtime, str_mtime);
        int dit = 2;
        char extra[3] = "\0\0";
        if (str_mode[0] == 'd') {
            extra[0] = '/';
        } else if (str_mode[0] == '-' && str_mode[3] == 'x') {
            extra[0] = '*';
            dit = 1;
        }
        strcpy(file_attri->mode, str_mode);
        file_attri->links = links;
        strcpy(file_attri->user_name, str_user_name);
        strcpy(file_attri->group_name, str_group_name);
        file_attri->size = size;
        strcpy(file_attri->mtime, str_mtime);
        strcpy(file_attri->filename, filename);
        strcpy(file_attri->extra, extra);
        file_attri->dit = dit;
    }
}

#endif

