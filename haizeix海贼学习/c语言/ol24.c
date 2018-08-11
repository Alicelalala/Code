/*************************************************************************
	> File Name: ol24.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月01日 星期二 23时14分52秒
 ************************************************************************/

#include <stdio.h> 
#include <inttypes.h>

int get_factorial(int n) {
    int mul = 1;
    for (int i = 1; i <= n; i++) {
        mul *= i;
    }
    return mul;
}

int main() {
    int factorial[12];
    int a[12] = {0};
    int temp[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int MAX = 1000000;
    int sum = 0;
    int i;
    for (i = 1; i <= 10; i++) {
        factorial[i] = get_factorial(i);
        if (factorial[i] > MAX) break;
        printf("%d\t", factorial[i]);
    }
    printf("\n");
    int n = 9;
    while (MAX) {
        if (factorial[n] <= MAX) {
             MAX -= factorial[n];
             ++a[n];
         } else {
            n--;
        }
    }
    for (i = 0; i <= 10; i++) {
        printf("%d\n", a[i]);
    }



    return 0;
}

