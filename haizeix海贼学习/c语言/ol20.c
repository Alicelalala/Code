/*************************************************************************
	> File Name: ol20.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月01日 星期二 17时21分13秒
 ************************************************************************/

#include <stdio.h>
#define BASE 10

int a[200] = {0};

int main() {
    int sum = 0;
    a[0] = a[1] = 1;

    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= a[0]; ++j) {
            a[j] *= i;
        }
        for (int j = 1; j <= a[0]; ++j) {
            if (a[j] < BASE) continue;
            a[j + 1] += a[j] / BASE;
            a[j] %= BASE;
            if (j == a[0]) {
                a[0]++;
            }
        }
    }
    for (int i = 1; i <= a[0]; ++i) {
        sum += a[i];
    }
    printf("%d", sum);
    return 0;
}

