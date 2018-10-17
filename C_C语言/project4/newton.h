/*************************************************************************
	> File Name: newton.h
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月07日 星期日 19时17分08秒
 ************************************************************************/

#ifndef _NEWTON_H
#define _NEWTON_H
double f(double);
double f_prime(double);
int newton(double (*fp)(double), double (*fp_prime)(double));
#endif
