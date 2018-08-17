/*************************************************************************
	> File Name: ol27.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月26日 星期六 17时15分18秒
 ************************************************************************/

#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <stdbool.h>

#define false 0
#define ture 1
#define MAX_N 1000
#define R_M_TEST_ROUND 30

int prime[MAX_N + 5] = {0};

void init_prime() {
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

bool R_M_TEST(int x) {
    if (x < 2) return false;
    for (int i = 0; i < R_M_TEST_ROUND; i++) {
        int m = x - 1;
        int ans = 1;
        int temp;
        int a = (rand() % (x - 1)) + 1;
        temp = a;
        while (m) {
            if (m & 1) ans = ans * temp % x;
            temp = temp * temp % x;
            m >>= 1;
        }
        if (ans != 1) return false;
    }
    return ture;
}

int howmang_n(int a, int b) {
    int num = 0;
    for (int i = 0; ; i++) {
        if (R_M_TEST(i * i + a * i + b)) num++;
        else break;
    }
    return num;
}

int Pim(int m) {
    for (int i = 1; i <= prime[0]; i++) {
        if (m % prime[i] == 0) return prime[i];
    }
    return 0;
}

int main() {
    srand(time(0));
    init_prime();
    int mult;
    int MAX_len = 0;
    for (int a = 1 - MAX_N; a < 1000; a++) {
        for (int i = 1; i <= prime[0]; i++) {
            if (a + prime[i] + 1 < 2) continue;
            if (a > 0) {
                int m = gcd(a, prime[i]);
                if (m == 1 || Pim(m) < MAX_len) continue;
            }
            int num = howmang_n(a, prime[i]);
            if (num > MAX_len) {
                mult = a * prime[i];
                MAX_len = num;
            }
        }
    }
    printf("%d", mult);
    return 0;
}

