/*************************************************************************
	> File Name: ol4.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 11时48分26秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int check(int32_t n) {
    int32_t m = n;
    int32_t a = 0;
    while (m) {
        a = a * 10 + m % 10;
        m /= 10;
    }
    return a == n;
}

int main() {
    int32_t max;
    for (int i = 100; i < 1000; i++) {
        for (int j = 100; j < 1000; j++) {
            if (check(i * j) && (i * j) > max) {
                max = i * j;
            }
        }
    }
    printf("%"PRId32"\n", max);
}
