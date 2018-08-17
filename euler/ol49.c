/*************************************************************************
	> File Name: ol49.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月11日 星期六 16时03分06秒
 ************************************************************************/

#include<stdio.h>

#define MAX 10000

int prime[MAX + 5] = {0};

void get_prime() {
    for (int i = 2; i <= MAX; i++) {
        if (!prime[i]) 
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int check_num(int m) {
    int left, right;

}
int main() {
    get_prime();
    for (int i = 1; i <= prime[0]; i++) {
        if (prime[i] > 1000) {

        }
    }
    return 0;
}
