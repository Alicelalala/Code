/*************************************************************************
	> File Name: check_size.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月20日 星期六 10时45分59秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

int check_size (char *filename, int size, char *dir) {
    struct stat statbuf;
    int flag;
    char command1[50] = {0};
    char command2[100] = {0};
    char basename[20] = {0};
    time_t _time;
    struct tm *lt;
    stat(filename, &statbuf);
    int file_size = statbuf.st_size;  // 1048576;
    if (file_size >= size) {
        flag = 0;
    } else {
        printf("return\n");
        return 0;
    }
    sprintf(command1, "basename %s", filename);
    printf("%s\n", command1);
    /*执行完这行代码，标准输出就装满，管道指向
     * 这个标准输出，fpr指向管道的读端
     */
    FILE *fpr = popen(command1, "r");

    fgets(basename, sizeof(basename), fpr);
    printf("%s\n", basename);
    time(&_time);
    lt = localtime(&_time);
    sprintf(command2, "cp -a %s %s/%s_%d%d%d%d", filename, dir, basename, lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour);
    system(command2);
    plose(fpr);
    return 0;
}

int main() {
    char file[50];
    char dir[50];
    strcpy(file, "test.txt");
    strcpy(dir, "/home/caohaiyan/Code/common.h/test_cp");
    int size = 10;
    check_size(file, size, dir);
    return 0;
}
