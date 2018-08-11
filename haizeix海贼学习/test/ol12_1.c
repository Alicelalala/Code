/*************************************************************************
	> File Name: ol12_1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月07日 星期二 09时58分12秒
 ************************************************************************/

#include <stdio.h> 

#define MAX 1000000

int prime[MAX + 5] = {0};
int mnum[MAX + 5] = {0};
int dnum[MAX + 5] = {0};

void initprime() {
    for (int i = 2; i <= MAX; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            mnum[i] = 1;
            dnum[i] = 2;
        }
        for (int j = 1; j <= prime[0]; j++) {
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
    initprime();
    int temp;
    for (int i = 1; i < MAX; i++) {
        if (i & 1) {
            temp = dnum[i] * dnum[(i + 1) / 2];
        } else {
            temp = dnum[i / 2] * dnum[i + 1];
        }
        if (temp > 500) {
            printf("%d\n", i * (i + 1) / 2);
            break;
        }
    }
    return 0;
}
