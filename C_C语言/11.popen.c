/*************************************************************************
	> File Name: 11.popen.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月20日 星期六 20时39分30秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

int check_size (char *filename, int size, char *dir) {
    struct stat statbuf;
    stat(filename, &statbuf);
    int file_size = statbuf.st_size;
    if (file_size < size) return 0;
    char *cp_file = (char *)malloc(sizeof(char) * 30);
    sprintf(cp_file, "%s%s", dir, filename);
    char buf[200];
    char command[50];
    sprintf(command, "cat %s 2>/dev/null", filename);
    FILE *fp = popen(command, "r");
    FILE *fpw = fopen(cp_file, "w");
    while ((fgets(buf, 5, fp)) != NULL) {
        fprintf(fpw, "%s", buf);
    }
    pclose(fp);
    fclose(fpw);
    return 1;
}

int main() {
    char *filename = "tt.c";
    char *dir = "./cp_";
    int size = 10;
    check_size(filename, size, dir);
    return 0;
}
