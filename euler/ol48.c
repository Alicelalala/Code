/*************************************************************************
	> File Name: ol48.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月11日 星期六 14时40分29秒
 ************************************************************************/

#include<stdio.h>

#define MAX 1000000

int sum[20] = {0};

void get_sum(int *mult) {
    for (int i = 1; i <= 10; i++) {
        sum[i] += mult[i];
    }
    for (int i = 1; i <= 10; i++) {
        if (sum[i] < 10) continue;
        sum[i + 1] += sum[i] / 10;
        sum[i] %= 10;
    }
}

void get_mult(int n, int m) {
    int ans[12] = {0};
    ans[0] = ans[1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= ans[0]; j++) {
            ans[j] *= n;
        }
        for (int j = 1; j <= ans[0]; j++) {
            if (j > 10) {ans[11] = 0; break;}
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            if (j == ans[0]) ans[0]++;
        }
    }
    get_sum(ans);
}
int main() {
    for (int i = 1; i <= 1000; i++) {
        get_mult(i, i);
    }
    for (int i = 10; i >= 1; i--) {
        printf("%d", sum[i]);
    }
    return 0;
}
