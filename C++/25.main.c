/*************************************************************************
	> File Name: 25.main.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月10日 星期四 20时34分54秒
 ************************************************************************/

#include <stdio.h>
#include "25.head.h"
int main() {
    demo *p = demo_init(1, 2);
    printf("a = %d\n", getI(p));
    printf("b = %d\n", getJ(p));
    printf("add = %d\n", add(p, 5));
    return 0;
}
