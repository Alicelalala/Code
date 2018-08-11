/*************************************************************************
	> File Name: ol21_1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月07日 星期二 10时16分54秒
 ************************************************************************/

#include<stdio.h>

#define MAX 10000

int prime[MAX + 5] = {0};
int isprime[MAX + 5] = {0};
int dsum[MAX + 5] = {0};

void initprime() {
    for (int i = 2; i <= MAX; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            isprime[i] = i;
            dsum[i] = i + 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                isprime[i * prime[j]] = isprime[i] * prime[j];
                dsum[i * prime[j]] = dsum[i] * (isprime[i] * prime[j] * prime[j] - 1) / (isprime[i] 
                * prime[j] - 1);
                break;
            } else {
                isprime[i * prime[j]] = prime[j];
                dsum[i * prime[j]] = dsum[i] * dsum[prime[j]];
            }
        }
    }
}
int main() {
    initprime();
    int sum = 0;
    for (int i = 2; i < MAX; i++) {
        dsum[i] -= i;
        printf("%d\t%d\n" , i, dsum[i]);
    }
    for (int i = 2; i < 10000; i++) {
        if (dsum[i] < MAX && dsum[i] != i && i == dsum[dsum[i]]) {
            sum += i;
            //printf("%d\n", dsum[i]);
        }
    }
    printf("%d\n", sum);
    return 0;
}
