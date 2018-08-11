/*************************************************************************
	> File Name: ol21.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月01日 星期二 20时00分47秒
 ************************************************************************/

#include <stdio.h>
#define MAX 10000

int factor_sum(int n) {
    int sum = 1;
    for (int i = 2; i * 2 <= n; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}




int main() {
    int sum = 0;
    int temp;
    int ans[MAX] = {0};
    for (int i = 2; i < MAX; ++i) {
        if (ans[i]) continue;
        temp = factor_sum(i);
        //printf("%d\t%d\n", i, temp);
        if (temp == i) continue;
        if (factor_sum(temp) == i) {
            if (temp >= MAX) {
                sum += i;
                printf("%d\n", i);
            } else {
                sum += temp + i;
                ans[temp] = 1;
                printf("%d\t%d\n", i, temp);
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}

