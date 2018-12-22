/*************************************************************************
	> File Name: makdir.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年12月16日 星期日 16时51分21秒
 ************************************************************************/

#include <stdio.h>
#include "head.h"

int main() {
    char filename[50];
    sprintf(filename, "mmmlog");
    if (access(filename, 0) == -1) {
        char command[50];
        sprintf(command, "mkdir %s", filename);
        FILE *fp = popen(command, "r");
        pclose(fp);
    } else {
        printf("已存在\n");

    }
    return 0;
}
