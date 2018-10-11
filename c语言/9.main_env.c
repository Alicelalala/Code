/*************************************************************************
	> File Name: 9.main_env.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月06日 星期六 13时21分42秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int main(int argc, char *argv[], char **env[]) {
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    for (char **p = env; p[0] != NULL; p++) {
        printf("%s\n", p[0]);
    }
    return 0;
}
