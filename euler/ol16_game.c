/*************************************************************************
	> File Name: ol16_game.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月06日 星期一 17时15分16秒
 ************************************************************************/

#include<stdio.h>

#define BASE 10000

int main() {
    int sum = 0;
    int a[200] = {0};
    a[0] = a[1] = 1;
    for (int i = 1; i <= 100; i++) {
        for (int k = 1; k <= a[0]; k++) {
            a[k] <<= 10;
        }
        for (int j = 1; j <= a[0]; j++ ) {
            if (a[j] < BASE) continue;
            a[j + 1] += a[j] / BASE;
            a[j] %= BASE;
            if (j == a[0]) a[0]++;
        }
    }
    for (int i = 1; i <= a[0]; i++) {
        while (a[i]) {
            sum += a[i] % 10;
            a[i] /= 10;
        }
    }
    printf("%d", sum);
}
