/*************************************************************************
	> File Name: 1.test.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年12月25日 星期二 18时34分59秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

int f() {
    return 5;
}
int g(void) {
    return 10;
}
int main() {
    printf("%d\n", f());
    printf("%d\n", g());
    return 0;
}

