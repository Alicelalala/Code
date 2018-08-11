/*************************************************************************
	> File Name: ol31.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月23日 星期一 18时30分20秒
 ************************************************************************/

#include <stdio.h>

int money[9] = {0, 1, 2, 5, 10, 20, 50, 100, 200};

int f(int k, int n) {
    if (k == 1) return 1;
    if (n < 0) return 0;
    if (n == 0) return 1;
    return f(k - 1, n) + f(k, n - money[k]);
}
int main() {
    printf("%d\n", f(8, 200));
    return 0;
}

