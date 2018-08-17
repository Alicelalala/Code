/*************************************************************************
	> File Name: ol24.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 09时22分27秒
 ************************************************************************/

#include<stdio.h>

int get_num(int k, int *num, int delta, int n) {
        int rank = k / delta + 1, now = 0;
    for (int i = 0; i < n; i++) {
                now += !(num[i]);
                if (now == rank) return i;
            
    }
        return -1;

}

int main() {
        int n, k, num[100] = {0}, delta = 1;
        scanf("%d%d", &n, &k);
        k--;
        for (int i = 1; i < n; i++) delta *= i;
    for (int i = 0; i < n; i++) {
                int digit = get_num(k, num, delta, n);
                printf("%d", digit);
                num[digit] = 1;
                k %= delta;
                if (i == n - 1) break;
                delta /= (n - 1 - i);
            
    }
        return 0;
}
