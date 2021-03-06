/*************************************************************************
	> File Name: ol7.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 14时48分30秒
 ************************************************************************/

#include<stdio.h>

#define MAX 1000000

int prime[MAX + 5] = {0};

int main() {
    for (int i = 2; i <= MAX; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
           if (i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    printf("%d", prime[10001]);
    return 0;
}
