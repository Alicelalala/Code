/*************************************************************************
	> File Name: ol47.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月04日 星期五 10时50分01秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#define MAX 1000000

int64_t prime[MAX + 5] = {0};

void init_prime() {
    for (int64_t i = 2; i <= MAX; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int64_t j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int get_factors(int n) {
    int num = 0;
    int temp = n;
    for (int i = 1; ; i++) {
        int p = 0;
        while(temp % prime[i] == 0) {
            temp /= prime[i];
            p = 1;
        }
        num += p;
        if (temp == 1) break;
    }
    if (num == 4) return 1;
    return 0;
}

int64_t main() {
    init_prime();
    for (int n = 647; ; n++) {
        if (get_factors(n) && get_factors(n + 1) && get_factors(n + 2) && get_factors(n + 3))
        {
            printf("%d", n);
            break;
        }
    }

    return 0;
}

