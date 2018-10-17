/*************************************************************************
	> File Name: dicsearch.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月07日 星期日 16时58分33秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "dicsearch.h"
#include "test.h"
#define EPSILON 1e-6
#define EQUAL 1e-7

/*double bisection(int p, int q, double (*func)(int, int, double));
double f(int p, int q, double x);
int main() {
    int p;
    int q;
    scanf("%d%d", &p, &q);
    printf("%.4f\n", bisection(p, q, f));
    return 0;
}*/

int bisection(int p, int q, double (*func)(int, int, double)) {
    double a = 20;
    double b = -20;
    double m;    
    m = (a + b) / 2.0;
    if(func(p, q, m) == 0) {            
        return m;    
    } 
    else {
        do {
            if(func(p, q, a) * func(p, q, m) < 0) {
                b = m;        
            }
            else {
                a = m;        
            }
                m = (a + b) / 2.0;
        }while(fabs(func(p, q, m))> EPSILON);
    }
    if(fabs(func(p, q, m)) < EQUAL) {
        return (int)m;
    }
    return 0;
}

double ff(int p, int q, double x) {
    return p * x + q;
}
