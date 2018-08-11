/*************************************************************************
	> File Name: ol21_game.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月06日 星期一 18时24分32秒
 ************************************************************************/

#include<stdio.h>

#define MAX 100000

int prime[MAX + 5] = {0};
int num[MAX + 5] = {0};

void init_prime() {
    for (int i = 2; i <= MAX; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            num[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                if (!prime[i]) {
                    num[i * prime[j]] = num[i] + i + prime[j] * prime[j];
                } else {
                    num[i * prime[j]] = num[i] + i;
                }
                break;
            } else {
                num[i * prime[j]] = 1 + i + prime[j];
            }
        }
    }
}
int main() {
    init_prime();
    int sum = 0;
    for (int i = 1; i < 100; i++) {
        printf("%d\t%d\n",i, num[i]);
        if (num[i] != i && num[i] == num[num[i]]) {
            sum += num[i];
         //   printf("%d\n", num[i]);
        }
    }
    printf("%d", sum);
    return 0;
}
