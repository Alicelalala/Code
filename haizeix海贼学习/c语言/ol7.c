/*************************************************************************
	> File Name: ol7.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月26日 星期四 17时56分47秒
 ************************************************************************/

#include <stdio.h> 
#define MAX 1000000

int main() {
    int prime[MAX] = {0};
    
    for (int i = 2; i <= MAX; ++i) {
        if (!prime[i]) prime[++prime[0]] = i;
        if (prime[0] == 10001) break;
        for (int j = 1; j <= prime[0]; ++j) {
            if (i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }

    printf("%d", prime[10001]);
    return 0;
}

