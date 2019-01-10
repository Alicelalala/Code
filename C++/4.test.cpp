/*************************************************************************
	> File Name: 4.test.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年12月27日 星期四 18时18分43秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

int main() {
    const int a = 5;
    int *p = (int *)&a;
    *p = 6;
    printf("%d %d\n", a, *p);
}
