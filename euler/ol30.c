/*************************************************************************
	> File Name: ol30.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 13时16分48秒
 ************************************************************************/

#include<stdio.h>
#include <math.h>
#include <inttypes.h>

#define MAX 1000000

int check(int n) {
    int m = n;
    int sum = 0;
    while (m) {
        sum += pow((m % 10), 5);
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
