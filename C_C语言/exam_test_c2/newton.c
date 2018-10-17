/*************************************************************************
	> File Name: newton.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月09日 星期二 09时41分12秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define EPSILON 1e-6

double f (double x) {
    return 2 * pow(x, 3) - 4 * pow(x, 2) + 3 * x - 6;
}

double f_prime (double x) {
    return 6 * pow(x, 2) - 8 * x + 3;
}

double newton (double (*f)(double), double (*f_prime)(double)) {
    int x = 1.5;
    while (fabs(f(x)) > EPSILON) {
        x = x - f(x) / f_prime(x);
    }
    return x;
}

int main() {
    printf("%f\n", newton(f, f_prime));
    return 0;
}
