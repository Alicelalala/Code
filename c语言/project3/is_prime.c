/*************************************************************************
	> File Name: is_prime.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月07日 星期日 11时24分45秒
 ************************************************************************/

#include <stdio.h>
#include "is_prime.h"
#include "test.h"

int is_prime(int x) {
    if (x <= 1) return 0;
    for (int i = 2; i * i < x; i++) {
        if (i % x == 0) return 0;
    }
    return 1;
}
