/*************************************************************************
	> File Name: ol16_1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月07日 星期二 09时12分44秒
 ************************************************************************/

#include<stdio.h>
#define BASE 10000

int main() {
    int sum = 0;
    int a[200] = {0};
    a[0] = a[1] = 1;
    for (int i = 0; i < 100; i++) {
        for (int j = 1; j <= a[0]; j++) {
            a[j] <<= 10;
        }
        for (int j = 1; j <= a[0]; j++) {
            if (a[j] < BASE) continue;
            a[j + 1] += a[j] / BASE;
            a[j] %= BASE;
            if (j == a[0]) {
                ++a[0];
            }
        }
    }
    for (int i = 1; i <= a[0]; i++) {
        //printf("%d\n", a[i]);
        while (a[i]) {
            sum += (a[i] % 10);
            a[i] /= 10;
        }
    }
    printf("%d", sum);
    return 0;
}
