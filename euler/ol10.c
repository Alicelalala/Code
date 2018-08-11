/*************************************************************************
	> File Name: ol10.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 15时28分02秒
 ************************************************************************/

#include<stdio.h>
#include <inttypes.h>

#define MAX 2000000

int64_t prime[MAX + 5] = {0};

int main() {
    int64_t sum = 0;
    for (int32_t i = 2; i <= MAX; ++i) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            printf("%"PRId32"\n", i);
            sum += i;
        }
        for (int32_t j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    printf("%"PRId64"\n", sum);
    return 0;
}
