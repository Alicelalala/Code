/*************************************************************************
	> File Name: ol46.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月02日 星期三 20时52分27秒
 ************************************************************************/

#include <stdio.h> 
#include <inttypes.h>

#define MAX 100000000

int64_t prime[MAX + 100] = {0};
int64_t ans[MAX + 100] = {0};

void get_prime() {
    ans[0] = ans[1] = 1;
    for (int64_t i = 2; i < MAX; i++) {
        if (!ans[i]) prime[++prime[0]] = i;
        for (int64_t j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX) break;
            ans[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}


int64_t main() {
    get_prime;
    for (int64_t i = 35; ; i+=2) {
        if (i > MAX) {
            printf("%"PRId64"\n", i);
            break;
        }
        if (!ans[i]) continue;
        int64_t f = 0;
        for (int64_t j = 1; 2 * j * j < i; j++) {
            if (!ans[i - 2 * j * j]) {
                f = 1;
                break;
            }
        }
        if (!f) {
            printf("%"PRId64"\n", i);
            break;
        }
    }

    return 0;
}
