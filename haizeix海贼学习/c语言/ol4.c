/*************************************************************************
	> File Name: ol4.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月26日 星期四 10时10分50秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int pal(int n) {
    int digits = floor(log10(n));
    int digit_num = pow(10, digits);
    int p = n * digit_num * 10;
    int sum = 0;
    int i;

    for (i = 0; i < digits; ++i) {
        int temp = n % 10;
        sum += temp * digit_num;
        n /= 10;
        digit_num /= 10;
    }
    return sum += p + n;
}

int Pal_m(int n) {
    int i;
    int low = ceil(sqrt(n));
    for (i = 100; i <= low; ++i) {
        if (n % i == 0) {
            if (floor(log10(n / i)) == 2) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int temp;
    int n;
    for (n = 997; n >= 100; --n) {
        temp = pal(n);
        if (Pal_m(temp)) {
            printf("%d\n", temp);
            break;
        } else continue;
    }
    return 0;
}
