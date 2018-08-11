/*************************************************************************
	> File Name: ol24_2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月02日 星期三 22时36分55秒
 ************************************************************************/

#include <stdio.h>

int get_mul(int n) {
    int mul = 1;
    for (int i = 1; i <= n; i++) {
        mul *= i;
    }
    return mul;
}

int get_num(int n, int k, int *num, int delta) {
    int rank = k / delta + 1, now = 0;
    for (int i = 0; i < n; i++) {
        now += !(num[i]);
        if (now == rank) return i;
    }
    return -1;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int temp = k - 1;
    int num[10] = {0};
    int delta = get_mul(n - 1);

    for (int i = 0; i < n; i++) {
        int digit = get_num(n, temp, num, delta);
        printf("%d", digit);
        num[digit] = 1;
        temp %= delta;
        if (i == n - 1) break;
        delta /= (n - 1 - i);
        
    }


    return 0;
}
