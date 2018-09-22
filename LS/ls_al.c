/*************************************************************************
	> File Name: ls2.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月17日 星期一 15时53分43秒
 ************************************************************************/

#include <stdio.h>
#include "ls_al_header.h"

int main(int argc, char **argv) {
    int i;
    if (argc == 2 && !strcmp(argv[1], "-a")) {
        lsShort("./");
        return 0;
    }
    if (argc == 2 && !strcmp(argv[1], "-l")) {
        lsLong("./", 0);
        return 0;
    }
    if (argc == 2 && !strcmp(argv[1], "-al")) {
        lsLong("./", 1);
        return 0;
   }
    if (argc > 2 && !strcmp(argv[1], "-l")) {
        for (i = 2; i < argc; i++) {
            printf("%s:\n", argv[i]);
            lsLong(argv[i], 0);
            if (i != argc - 1) {
                printf("\n");
            }
        }
        return 0;
    } else if (argc > 2 && !strcmp(argv[1], "-a")) {
        for (i = 2; i < argc; i++) {
            printf("%s:\n", argv[i]);
            lsShort(argv[i]);
            if (i != argc - 1) {
                printf("\n");
            }
        }
        return 0;
    } else if (argc > 2 && !strcmp(argv[1], "-al")) {
        for (i = 2; i < argc; i++) {
            printf("%s:\n", argv[i]);
            lsLong(argv[i], 1);
            if (i != argc - 1) {
                printf("\n");
            }
        }
        return 0;
    }
    return 0;
}

