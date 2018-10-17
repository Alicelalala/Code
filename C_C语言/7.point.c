/*************************************************************************
	> File Name: 7.point.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月06日 星期六 11时02分41秒
 ************************************************************************/

#include <stdio.h>

struct Data {
    int x, y;
};

int main() {
    struct Data a[2], *p = a;
    a[0].x = 1;
    a[1].x = 2;
    a[0].y = 3;
    a[1].y = 4;
    printf("%d\n", (a + 1)->x);
    printf("%d\n%d\n", (&a[0] + 1)->x, p[1].x);
    printf("%d\n", (p + 1)->x);
    printf("%d\n", (&(*p) + 1)->x);
    return 0;
}
