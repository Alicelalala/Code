/*************************************************************************
	> File Name: ol7_10001st_prime.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月06日 星期一 14时46分50秒
 ************************************************************************/
//素数筛
#include <stdio.h>
#include <inttypes.h>

#define MAX 1000000

int64_t prime[MAX + 5] = {0};
int64_t prime2[MAX + 5] = {0};
int64_t main() {
    for (int64_t i = 2; i <= MAX; i++) {
        if (!prime[i])  {
            prime2[++prime[0]] = i;
        }
        for (int64_t j = i * i; j <= MAX; j+=i) {
            prime[j] = 1;
        }
    }
    printf("%"PRId64"\n",prime2[10001]);
    printf("%"PRId64"\n", prime[0]);
    return 0;
}

