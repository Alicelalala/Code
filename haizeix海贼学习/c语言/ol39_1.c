/*************************************************************************
	> File Name: ol39_1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月06日 星期日 18时56分02秒
 ************************************************************************/

#include <stdio.h>
#define MAX 1000

int num[MAX + 5] = {0};

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

void get_num(int a, int b, int c) {
    int p = a + b + c;
    for (int i = p; i <= MAX; i += p) {
        num[i]++;
    }
}
int main() {
    for (int i = 2; i * i <= MAX; i++) {
        for (int j = 1; j < i; j++) {
            if (gcd(i, j) != 1) continue;
            a = i * i - j * j;
            b = 2 * i * j;
            c = i * i + j * j;
        }
    }
}

