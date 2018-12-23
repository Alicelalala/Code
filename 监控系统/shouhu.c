/*************************************************************************
	> File Name: shouhu.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年12月23日 星期日 13时11分07秒
 ************************************************************************/

#include <stdio.h>
#include "head.h"

int main() {
    pid_t pid;
    int i;
    pid = fork();
    if (pid == -1) return -1;
    else if (pid != 0) {
        exit(EXIT_SUCCESS);
    } 
        while(1) {
            int a = 0;
        }
    
    return 0;
}
