/*************************************************************************
	> File Name: check_size.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月19日 星期五 15时38分59秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>

int check_size (char *filename, int size, char *dir) {
    struct stat statbuf; //获取文件属性
    stat(filename, &statbuf); //定义stat(const char *filename, struct stat *buf)
    int file_size = statbuf.st_size;
    if (file_size < size) return 0;
    time_t _time;
    struct tm *t;
    time(&_time);
    t = localtime(&_time);
    
    char cp_filename[50];
    char buf[20];
    sprintf(cp_filename, "%s/%s", dir, filename);
    FILE *fpr = fopen(filename, "r");
    FILE *fpw = fopen(cp_filename, "w");
    while (!feof(fpr)) {
        fread(buf, 1, 5, fpr);
        fwrite(buf, 1, 5, fpw);
    }
    fclose(fpr);
    fclose(fpw);
    printf("cp -a %s %s %d_%d_%d_%d:%d:%d\n", filename, cp_filename, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    return size;
}

int main() {
    int size, len;
    char filename[25];
    char dir[25];
    strcpy(filename, "test.txt");
    strcpy(dir, "./test_cp");
    size  = 10;
    check_size(filename, size, dir);
}
