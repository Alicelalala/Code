/*************************************************************************
	> File Name: 1.test.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年12月25日 星期二 18时26分13秒
 ************************************************************************/

#include <stdio.h>
int f();
int g(void);
int main() {
    printf("%d\n", f(1, 2, 3, 4, 6, 8));
    printf("%d\n", g());
    return 0;
}
int f() {
    return 5;
}
int g(void) {
    return 10;
}
