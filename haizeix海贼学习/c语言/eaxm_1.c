/*************************************************************************
	> File Name: eaxm_1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月09日 星期三 23时57分36秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#define MAX_N 1000000

int prime[MAX_N + 5] = {0};
int64_t dnum[MAX_N + 5] = {0};

int main() {
    int64_t max1 = 0;
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                int n = i / prime[j] + 1;
                dnum[i * prime[j]] = prime[j] * (pow(prime[j], n) - 1) / (prime[j] - 1);
                break;
            } else {
                dnum[i * prime[j]] = dnum[i] + dnum[prime[j]] + i * prime[j];
            }
        }
    }
    for (int i = 2; i <= 100; i++) {
        printf("%d\t" "%"PRId64"\n",i, dnum[i]);
        if (dnum[i] > max1) {
            max1 = dnum[i];
        }
    } 



    printf("%"PRId64"\n", max1);
    return 0;
}

