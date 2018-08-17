/*************************************************************************
	> File Name: ol36.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 13时52分50秒
 ************************************************************************/

#include<stdio.h>
#include <inttypes.h>

#define MAX 1000000

int check(int n) {
    if (n < 10) return 1;
    int m = n;
    int x = 0; 
    while (m) {
        x = x * 10 + m % 10; 
        m /= 10;
    }
    return x == n;
}
int b_check(int n) {
    int m = n;
    int i = 0;
    int num[50];
    while (m) {
        num[i++] = m % 2;
        m /= 2;
    }
    for (int j = 0; j * 2 <= i; j++) {
        if (num[j] != num[i - j -1]) return 0;
    }
    return 1;
}

int main() {
    int32_t sum = 0;
    for (int i = 1; i < MAX; i+=2) {
        if (check(i) && b_check(i)) {
            printf("%d\n", i);
            sum += i;
        }
    }
    printf("%"PRId32"\n", sum);
    return 0;
}
