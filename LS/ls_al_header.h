/*************************************************************************
	> File Name: ls_header.h
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月17日 星期一 16时06分11秒
 ************************************************************************/

#ifndef _LS_HEADER_H
#define _LS_HEADER_H

#include <stdio.h>
#include <dirent.h> 
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "ls_util.h"

struct attribute file_attribute[200]; // maximum 200

void lsLong (char *dirname, int bit) {
    DIR *mydir = opendir(dirname);
    char filename[50];
    int file_num = 0;
    if (mydir == NULL) {
        //显示单个文件详细信息
        strcpy(filename, dirname);
        ls_long_file("./", filename, &file_attribute[0]);
        ++file_num;
    } else {
        //考虑用户输入文件夹没有输入反斜杠的情况
        int len = strlen(dirname);
        if (dirname[len - 1] != '/') {
            dirname[len] = '/';
            dirname[len + 1] = '\0';
        }
        //循环得到当前目录下的所有文件名，并存储在自定义的结构中
        struct dirent *mydirent;
        while ((mydirent = readdir(mydir)) != NULL) {
            char filename[50];
            strcpy(filename, mydirent->d_name);
            if (bit == 0) {
                if ( filename[0] != '.' ) {
                    ls_long_file(dirname, filename, &file_attribute[file_num++]);
                }
            } else {
                ls_long_file(dirname, filename, &file_attribute[file_num++]);
            }
        }
        closedir(mydir);
    }
    //格式化输出时，考虑每个属性值的范围
    int max_mode = 0;
    int max_links = 0;
    int max_user_name = 0;
    int max_group_name = 0;
    int max_size = 0;
    int max_mtime = 0;
    int max_filename = 0;
    int max_extra = 0;
    int i;
    for (i = 0; i < file_num; ++i) {
        if (max_mode < strlen(file_attribute[i].mode)) {
            max_mode = strlen(file_attribute[i].mode);
        }
        if (max_links < f(file_attribute[i].links)) {
            max_links = f(file_attribute[i].links);
        }
        if (max_user_name < strlen(file_attribute[i].user_name)) {
            max_user_name = strlen(file_attribute[i].user_name);
        }
        if (max_group_name < strlen(file_attribute[i].group_name)) {
            max_group_name = strlen(file_attribute[i].group_name);
        }
        if (max_size < f(file_attribute[i].size)) {
            max_size = f(file_attribute[i].size);
        }
        if (max_mtime < strlen(file_attribute[i].mtime)) {
            max_mtime = strlen(file_attribute[i].mtime);
        }
        if (max_filename < strlen(file_attribute[i].filename)) {
            max_filename = strlen(file_attribute[i].filename);
        }
        if (max_extra < strlen(file_attribute[i].extra)) {
            max_extra = strlen(file_attribute[i].extra);
        }
    }
    for (i = 0; i < file_num; ++i) {
        char format[50];
        //定义输出格式
        if (file_attribute[i].extra[0] == '*') {
        sprintf(format, "%%%ds %%%dd %%%ds %%%ds %%%dld %%%ds \33[32m\33[1m%%s\33[0m%%s\n",
                max_mode, max_links, max_user_name, max_group_name, max_size, max_mtime);
        //按照定义的输出格式输出
        } else if (file_attribute[i].extra[0] == '/') {
            sprintf(format, "%%%ds %%%dd %%%ds %%%ds %%%dld %%%ds \33[34m\33[1m%%s\33[0m%%s\n", max_mode, max_links,
                   max_user_name, max_group_name, max_size, max_mtime);
        } else {
            sprintf(format, "%%%ds %%%dd %%%ds %%%ds %%%dld %%%ds %%s%%s\n", max_mode, max_links, 
                   max_user_name, max_group_name, max_size, max_mtime);
        }
        printf(format, file_attribute[i].mode, file_attribute[i].links, file_attribute[i].user_name, file_attribute[i].group_name, file_attribute[i].size, file_attribute[i].mtime, file_attribute[i].filename, file_attribute[i].extra);
    }
}

void lsShort (char *dirname) {
    DIR *mydir = opendir(dirname);
    //用来暂时存储要显示的目录下的所有文件名，可以看到最大可以支持200个文件
    char filenames[10000][50];
    int file_num = 0;
    if (mydir == NULL) {
        //直接显示该文件
        printf("%s\n\n", dirname);
        return;
    } else {
        int len = strlen(dirname);
        if (dirname[len - 1] != '/') {
            dirname[len] = '/';
            dirname[len + 1] = '\0';
        }
        //　循环检查下面有多少文件，并把文件名全部放到filenames数组里
        struct dirent *mydirent;
        while ((mydirent = readdir(mydir)) != NULL) {
            char fname[50];
            strcpy(fname, mydirent->d_name);
            strcpy(filenames[file_num], mydirent->d_name);
            file_num++;
        }
        closedir(mydir);
    }
    int i, j;
    //确定所有文件里面最长的文件名长度
    int max_len = 0;
    for (i = 0; i < file_num; i++) {
        int len = strlen(filenames[i]);
        if (len > max_len) {
            max_len = len + 1;
        }
    }
    //得到当前终端的分辨率
    int cols = 80;
    int lines = 24;
    getTerminatorSize(&cols, &lines);
    char format[20];
    //格式化输出，当长度大于终端的列数时换行
    int current_len = 0;
    char type[3];
    for (i = 0; i < file_num; i++) {
        type[0] = '\0';
        lsshort_type(dirname, filenames[i], type);
        if (type[0] == '*') {
            sprintf(format, "\33[32m\33[1m%%-%ds\33[0m", max_len);
        } else if (type[0] == '/') {
            sprintf(format, "\33[34m\33[1m%%-%ds\33[0m", max_len);
        } else {
            sprintf(format, "%%-%ds", max_len);
        }
        printf(format, filenames[i]);
        current_len += max_len + 2;
        if (current_len + max_len + 2 > cols) {
            printf("\n");
            current_len = 0;
        }
    }
    printf("\n");
}



#endif
