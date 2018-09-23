/*************************************************************************
	> File Name: digui.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月20日 星期四 18时43分13秒
 ************************************************************************/

#include <stdio.h>

int factorial (int x) {
    if (x == 1) return 1;
    return x * getmult(x - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", getmult(n));
    return 0;
}
