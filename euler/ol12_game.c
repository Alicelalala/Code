/*************************************************************************
	> File Name: ol12_game.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月06日 星期一 16时25分55秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

#define MAX 100000000

int64_t prime[MAX + 5] = {0};
int64_t mnum[MAX + 5] = {0};
int64_t dnum[MAX + 5] = {0};

void init_prime() {
    for (int64_t i = 2; i <= MAX; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            mnum[i] = 1;
            dnum[i] = 2;
        }
        for (int64_t j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mnum[i * prime[j]] = mnum[i] + 1;
                dnum[i * prime[j]] = dnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
                break;
            } else {
                mnum[i * prime[j]] = 1;
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
            }
        }
    }
}
int main() {
    init_prime();
    for (int64_t i = 1; i * (i + 1) / 2 < MAX; i++) {
        if (dnum[i * (i + 1) / 2] > 500) {
            printf("%d\n", i * (i + 1) / 2);
            break;
        }
    }
    return 0;
}

