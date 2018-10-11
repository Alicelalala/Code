/*************************************************************************
	> File Name: newton.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月07日 星期日 17时12分05秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "newton.h"
#include "test.h"
#define EPSILON 1e-6
#define EQUAL 1e-7

double f(double x) {
    //return 2 * pow(x, 3) - 4 * pow(x, 2) + 3 * x - 6;
    return 2 * x * x * x - 4 * x * x + 3 * x - 6;
}

double f_prime(double x) {
    //return 6 * pow(x, 2) - 8 * x + 3;
    return 6 * x * x - 8 * x + 3;
}

int newton(double (*fp)(double), double (*fp_prime)(double)) {
    double x = 1.5;
    while (fabs(fp(x)) > EPSILON){
        x = x - fp(x) / fp_prime(x);    
    }
    if (fabs(fp(x)) < EQUAL) {
        return x;
    }
    return 0;
}

/*int main() {
    printf("%g\n", newton(f, f_prime));
//   printf("%g\n", newton(h, h_prime));
    return 0;
}*/
