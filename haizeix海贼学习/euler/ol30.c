/*************************************************************************
	> File Name: ol30.c
	> Author: 
	> Mail: 
	> Created Time: 2018年06月05日 星期二 10时02分10秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000000

int F_powers(int n) {
    int temp = n;
    int sum = 0;
    while (n) {
        int p = (int) pow(n % 10, 5);
        sum += p;
        n /= 10;
    }
    
    return sum == temp;
}
int main() {
    int sum = 0;
    for (int i = 10; i < MAX; i++) {
        if (F_powers(i)) sum += i;
    }
    printf("%d", sum);
    return 0;
}

