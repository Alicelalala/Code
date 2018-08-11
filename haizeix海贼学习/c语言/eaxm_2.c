/*************************************************************************
	> File Name: eaxm_2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月09日 星期三 23时38分04秒
 ************************************************************************/

#include <stdio.h>

#define MAX 100000

int ans[MAX + 5] = {0};

int main() {
    ans[0] = ans[1] = 1;
    int x;
    scanf("%d", &x);
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= ans[0]; j++) {
            ans[j] *= i;
        }
        for (int k = 1; k <= ans[0]; k++) {
            if (ans[k] >= 10) {
                ans[k + 1] += ans[k] / 10;
                ans[k] %= 10;
                if (k == ans[0]) ans[0]++;
            }
        }
    }
    for (int i = ans[0]; i > 0; i--) {
        printf("%d", ans[i]);
    }
    return 0;
}

