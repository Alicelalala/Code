/*************************************************************************
	> File Name: 2.test.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年12月25日 星期二 18时43分32秒
 ************************************************************************/

#include <stdio.h>

int f();
struct {
    int f();
};

int f() {
    printf("55555\n");
    return 0;
}

int main() {
    struct sut;
    sut.f();
    return 0;
}
