/*************************************************************************
	> File Name: ol46_3.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月03日 星期四 19时55分41秒
 ************************************************************************/

#include <stdio.h>


#define MAX 1000000

int prime[MAX + 5] = {0};
int ans[MAX + 5] = {0};

void get_prime() {
    ans[0] = ans[1] = 1;
    for (int i = 2; i <= MAX; i++) {
        if (!ans[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX) break;
            ans[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    get_prime();
    for (int i = 35;i < MAX ; i += 2) {
        int f = 0;
        if (!ans[i]) continue;
        for (int j = 1; 2 * j * j < i; j++) {
            int temp = i - 2 * j * j;
            if (ans[temp] == 0) {
                printf("%d = %d + %d\n", i, temp, 2*j*j);
                f = 1;
                break;
            }
        }
        if (f == 0) {
            printf("%d\n", i);
            break;
        }
    }
    /*for (int i = 35; i < MAX; i+=2) {
        if (ans[i] == 1) {
            printf("%d\n", i);
        }
    }*/
    return 0;
}

