/*************************************************************************
	> File Name: ol34.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 13时32分36秒
 ************************************************************************/

#include<stdio.h>
#include <inttypes.h>

#define MAX 10000000

int check(int n) {
    int m = n;
    int sum = 0, mult;
    while (m) {
        mult = 1;
        int p = m % 10;
        for (int i = 1; i <= p; i++) {
            mult *= i;
        }
        sum += mult;
        m /= 10;
    }
    return sum == n;
}

int main() {
    int32_t sum = 0;
    for (int i = 10; i < MAX; i++) {
        if (check(i)) {
            printf("%d\n", i);
            sum += i;
        }
    }
    printf("%"PRId32"\n", sum);
    return 0;
}
