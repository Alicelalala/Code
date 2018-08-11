/***************************
	> Created Time: 2018年05月01日 星期二 22时15分20秒
 ************************************************************************/

#include <stdio.h>
#define MAX 28123

int ans[MAX * 2];
int abundant[MAX + 100];
int num = 0;

void get_abundant(int n) {
    int sum = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i * i == n) {
                sum += i;
            } else {
                sum += i + n / i;
            }
        }
    }
    if (sum > n) {
        abundant[num++] = n;
    }
}
int main() {
    int sum = 0;
    for (int n = 12; n < MAX; ++n) {
        get_abundant(n);
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            ans[abundant[i] + abundant[j]] = 1;
        }
    }

    for (int i = 0; i <= MAX; i++) {
        if (!ans[i]) {
            sum += i;
        }
    }

    printf("%d\n", sum);


    return 0;
}

