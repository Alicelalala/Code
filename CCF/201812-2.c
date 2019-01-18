/*************************************************************************
	> File Name: 201912-2.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月14日 星期一 16时05分28秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int main() {
    long long a[4], n, bit, t;
    scanf("%lld%lld%lld", &a[1], &a[2], &a[3]);
    long long ryg = a[1] + a[2] + a[3];
    scanf("%lld", &n);
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
        scanf("%lld%lld", &bit, &t);
        if (bit == 0) {
            sum += t;
            continue;
        }
        long long temp = t - (sum % ryg);
        while (temp <= 0) {
            if (bit == 1) bit = 3;
            else bit = bit - 1;
            temp += a[bit];
        }
        if (bit == 2) {
            sum += temp + a[1];
        }
        else if (bit != 3) {
            sum += temp;
        }
    }
    printf("%lld\n", sum);
    return 0;
}
