/*************************************************************************
	> File Name: ol33.c
	> Author: 
	> Mail: 
	> Created Time: 2018年06月05日 星期二 15时47分21秒
 ************************************************************************/

#include <stdio.h>

int gcd(int n, int m) {
    if (!m) return n;
    return gcd(m, n % m);
}
int main() {
    int ans1 = 1, ans2 = 1;
    int x1, x2, y1, y2;
    for (int i = 10; i < 100; i++) {
        for (int j = i + 1; j < 100; j++) {
            x1 = i / 10; x2 = i % 10;
            y1 = j / 10; y2 = j % 10;
            if (!x1 || !x2 || !y1 || !y2) continue;
            if (x1 == y1 && x2 * j == i * y2) {
                ans1 *= i;
                ans2 *= j;
                printf("%d\t%d\n", i, j);
            }
            if (x1 == y2 && x2 * j == i * y1) {
                ans1 *= i;
                ans2 *= j;
                printf("%d\t%d\n", i, j);
            }
            if (x2 == y1 && x1 * j == i * y2) {
                ans1 *= i;
                ans2 *= j;
                printf("%d\t%d\n", i, j);
            }
            if (x2 == y2 && x1 * j == i * y1) {
                ans1 *= i;
                ans2 *= j;
                printf("%d\t%d\n", i, j);
            }

        }
    }
    int factor = gcd(ans1, ans2);
    printf("%d", ans2 / factor);
    return 0;
}

