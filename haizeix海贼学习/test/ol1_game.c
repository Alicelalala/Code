/*************************************************************************
	> File Name: ol1_game.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月07日 星期二 11时37分00秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX 100

int prime[MAX + 5] = {0};
int mnum[MAX + 5] = {0};
int dnum[MAX + 5] = {0};

void initprime() {
    for (int i = 2; i <= MAX; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            mnum[i] = 1;
            dnum[i] = i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mnum[i * prime[j]] = mnum[i] + 1;
                dnum[i * prime[j]] = dnum[i] * pow(prime[j], (mnum[i] + 1) * 
                (mnum[i] + 2) / 2) / pow(prime[j], (mnum[i] + 1) * mnum[i] / 2);
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
    for (int i = 2; i < MAX; i++) {
        printf("%d\t%d\n", i, dnum[i]);
    }
    return 0;
}
