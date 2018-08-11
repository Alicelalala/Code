/*************************************************************************
	> File Name: ol24_1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月02日 星期三 20时18分53秒
 ************************************************************************/

#include <stdio.h>

int get_num(int n, int *num, int delta) {
    int rank = n / delta + 1, now = 0;
    for (int i = 0; i < 6; i++) {
        now += !(num[i]);
        if (now == rank) return i;
    }
    return -1;
}

int main() {
    int n = 126, num[6] = {0}, delta = 120;
    for (int i = 0; i < 6; i++) {
        int digit = get_num(n, num, delta);
        printf("%d", digit);
        num[digit] = 1;
        n %= delta;
        if (i == 5) break;
        delta /= (5 - i);
    }


    return 0;
}

