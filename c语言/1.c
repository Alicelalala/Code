/*************************************************************************
	> File Name: 1.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月18日 星期二 18时29分27秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            printf("FOOLISH\n");
            return 0;
        }
        if (n < 60) {
            printf("FALL\n");
        } else if (n < 75) {
            printf("MEDIUM\n");
        } else {
            printf("GOOD\n");
        }
    }
    return 0;
}
