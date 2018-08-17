/*************************************************************************
	> File Name: ol32.c
	> Author: 
	> Mail: 
	> Created Time: 2018年06月05日 星期二 10时52分50秒
 ************************************************************************/

#include <stdio.h> 
#include <math.h>
#include <stdbool.h>

#define false 0
#define true 1

int canAdd[100000] = {0};

int get_digits(int n, int m) {
    int sum = 0;
    sum += floor(log10(n)) + 1;
    sum += floor(log10(m)) + 1;
    sum += floor(log10(n * m)) + 1; 
    return sum;
}

bool pandigital(int n, int *num) {
    while (n) {
        if (n % 10 == 0) return false;
        if (num[n % 10 - 1]) return false;
        num[n % 10 - 1] = 1;
        n /= 10;
    }
    return true;
}

bool IsPandigital(int i, int j) {
    int num[9] = {0};
    if (!pandigital(i, num)) return false;
    if (!pandigital(j, num)) return false;
    if (!pandigital(i * j, num)) return false;
    return true;
}

int main() {
    int sum = 0;
    for (int i = 2; i < 100; i++) {
        for (int j = i + 1; ; j++) {
            if (get_digits(i, j) < 9) continue;
            else if (get_digits(i, j) > 9) break;
            if (IsPandigital(i, j) && !canAdd[i * j]) {
                sum += (i * j);
                canAdd[i * j] = 1;
            }
    }
}
    printf("%d\n", sum);
    return 0;
}

