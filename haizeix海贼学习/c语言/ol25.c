/*************************************************************************
	> File Name: ol25.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月02日 星期三 14时22分55秒
 ************************************************************************/

#include <stdio.h>
#define BASE 10
#define MAX_N 1000
#define MAX_L 1000000

int fib[MAX_L + 5][MAX_N + 5] = {0};

int main() {
    fib[0][1] = 0;
    fib[1][1] = 1;
    int num = 1;
    int i, j;
    
    for (i = 2; i <= MAX_L; ++i) {
        for (j = 1; j <= num; j++) {
            fib[i][j] = fib[i - 1][j] + fib[i - 2][j];
            if (fib[i][j] < BASE) continue;
            fib[i][j + 1] += fib[i][j] / BASE;
            fib[i][j] %= BASE;
            if (j == num) {
                num++;
            }
        }
        if (num >= 1000) {
            printf("%d\n", i);
        }
    }
    return 0;
}



