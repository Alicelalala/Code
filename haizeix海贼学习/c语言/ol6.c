/*************************************************************************
	> File Name: ol6.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月26日 星期四 17时46分48秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int sum_mul;
    int sum = 0;
    int temp;

    for(int i = 1; i <= 100; i++) {
        temp = i * i;
        sum += temp;
    }

    temp = (1 + 100) * 100 / 2;
    sum_mul = temp * temp;

    int differ = sum_mul - sum;

    printf("%d", differ);
    return 0;
}

