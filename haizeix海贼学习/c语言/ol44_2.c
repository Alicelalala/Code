/*************************************************************************
	> File Name: ol44_2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月03日 星期四 23时20分07秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

#define MAX 100000000
int64_t ans[MAX + 5] = {0};

int64_t get_value(int64_t n) {
    return n * (3 * n - 1) / 2;
}

void pentagon() {
    for (int64_t i = 1; ; i++) {
        int64_t temp = get_value(i);
        if (temp > MAX) break;
        ans[temp] = 1;
    }
}

int64_t main() {
    pentagon();
    int64_t minD = 10000000;
    int64_t p1, p2;
    int f = 0;
    for (int64_t i = 1; ; i++) {
        p1 = get_value(i);
        for (int64_t j = i - 1; j > 0; j--) {
            p2 = get_value(j);
            if (!ans[p1 + p2] || !ans[p1 - p2]) continue;
            if (ans[p1 + p2] && ans[p1 - p2]) {
                minD = p1 - p2;
                f = 1;
                break;
            }
        }
        if (f == 1) break;
    }
    printf("%"PRId64"\n", minD);
    return 0;
}
