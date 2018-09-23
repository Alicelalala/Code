/*************************************************************************
	> File Name: 2.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月18日 星期二 18时52分23秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        switch (n) {
            case 1: printf("one\n"); break;
            case 2: printf("two\n"); break;
            case 3: printf("three\n"); break;
            default: printf("error\n"); break;
        }
    }
    return 0;
}
