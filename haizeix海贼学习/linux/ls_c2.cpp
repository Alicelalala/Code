/*************************************************************************
	> File Name: ls_c2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月21日 星期一 18时39分21秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>

void file_mode(struct stat *buf) {
    int i;
    char buff[10] = {"------"};
    switch (buf -> st_mode & S_IFMT) //按位＆获取文件基本属性
    {
        case S_IFIFO: buff[0] = 'f'; break;
        case S_IFDIR: buff[0] = 'd'; break;
        case S_IFSOCK: buff[0] = 's'; break;
        case S_IFBLK: buff[0] = 'b';break;
        case S_IFLNK: buff[0] = 'l';
        break;
    }

    if (buf -> st_mode & S_IRUSR) {
        buff[1] = 'r';
    }

    if (buf -> st_mode & S_IWUSR) {
        buff[2] = 'w';
    }

    if (buf -> st_mode & S_IXUSR) {
        buff[3] = 'x';
    }

    if (buf -> st_mode & S_IWGRP) {
        buff[4] = 'r';
    }

    if (buf -> st_mode & S_IWGRP) {
            buff[5] = 'w';
    }

    if (buf -> st_mode & S_IXGRP) {
        buff[6] = 'x';
    }

    if (buf -> st_mode & S_IWOTH) {
        buff[8] = 'w';
    }

    if (buf -> st_mode & S_IXOTH) {
        buff[9] = 'x';
    }

    for (int i = 0; i < 10; i++) {
        printf("%c", buff[i]);
    }
}

void file_gid_uid(int uid, int gid) {
    struct passwd *ptr;
    struct group *str; //结构体中存放文件所有者名和文件所有者组名
    ptr = getpwuid(uid); //调用函数获取文件所有者指针
    str = getgrgid(gid); //调用函数获取文件所有者组指针
    printf("\t%s\t%s", ptr ->pw_name, str -> gr_name); //打印文件所有者和文件所有者组
}

void file_operation(char **argv) {
    DIR* fd; //定义文件夹类型
    struct dirent* fp; //fp文件夹返回值
    struct stat buf;
    int ret; //获取文件属性
    char temp[100]; //中间变量存放文件路径
    if ((fd = opendir(argv[1])) == NULL) //打开文件夹　{
    perror("open file fail!");
    exit(0);
    }
    
    while ((fp = readdir(fd)) != NULL) //循环读取文件夹中的文件信息 {
        strcpy(temp, argv[1]); //将路径付给中间变量temp
        strcat(temp, fp -> d_name); //把文件名字添加到路径后面形成完整的路径
        if ((ret = stat(temp, &buf)) == -1) //获取文件基本属性　{
        perror("stat");
        exit(0);
        }
        file_mode(&buf); //文件属性（目录，链接......，可读，可写，可执行）
        printf("%ld", buf.st_nlink); //打印链接数
        file_gid_uid(buf.st_uid, buf.st_gid); //调用函数打印出文件所有者和文件所有者组
        printf("\t%ld", buf.st_size); //打印文件大小

        //Time();//获取时间
        printf("\t%.12s", 4 + ctime(&buf.st_mtime));
        printf("%s\n", fp -> d_name); //打印文件名
    }

    closedir(fd)
    }

int main(int argc, char **argv) {
        if (argc == 1) {
            argv[1] = "./"; //缺省为当前目录
        }

        file_operation(argv);
        return 0;
}

