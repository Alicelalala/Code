/*************************************************************************
	> File Name: 4.test.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年12月27日 星期四 18时13分48秒
 ************************************************************************/

#include <stdio.h>

int main() {
    const int a = 5;
    int *p = (int *)&a;
    *p = 6;
    printf("%d %d\n", a, *p);
}
