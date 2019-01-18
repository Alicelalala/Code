/*************************************************************************
	> File Name: main.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月16日 星期三 11时52分43秒
 ************************************************************************/

#include <stdio.h>
#include "head.h"
#include "head.c"

int main() {
    demo *d = demo_init(1, 2);
    printf("a = %d\n", getA(d));
    printf("b = %d\n", getB(d));
    printf("add = %d\n", add(d, 5));
    free_demo(d);
    deverid *d1 = deverid_init(1, 2, 3);
    printf("a = %d\n", getA(d1));
    printf("b = %d\n", getB(d1));
    printf("c = %d\n", getC(d1));
    printf("add1 = %d\n", add1(d1, 5));
    free_deverid(d1);
    return 0;
}

