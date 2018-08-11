/*************************************************************************
	> File Name: ol39.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月06日 星期日 14时06分20秒
 ************************************************************************/

#include <stdio.h>
#define MAX 1000

int num[MAX + 5] = {0};

int gcd(int a, int b) {
    if (!b) return a;
    return (b, a % b);
}

void get_perimeter() {
    for (int n = 2; ; n++) {
        if (n * n > MAX) break;
        for (int m = 1; m < n; m++) {
            if (gcd(n, m) != 1) continue;
            int a = n * n - m * m;
            int b = 2 * n * m;
            int c = n * n + m * m;
            int temp = a + b + c;
            int p = temp;
            while (temp <= MAX) {
                num[temp]++;
                temp += p;
            }
        }
    }
    return ;
}

int main() {
    get_perimeter();
    int len = 0, p;
    for (int n = 2; n <= MAX; n++) {
        if (num[n] > len) {
            len = num[n];
            p = n;
        }
    }
    printf("%d\n%d %d\n", num[120], len, p);


    return 0;
}

