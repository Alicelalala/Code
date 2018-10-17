/*************************************************************************
	> File Name: 5.union.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月06日 星期六 09时28分00秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

union IP {
    struct {
        unsigned char arr[4];
    }ip;
    unsigned int num;//每个存储长度一样(struct ip和int)
};

int main() {
    int a, b, c, d;
    IP ip;
    while (scanf("%d.%d.%d.%d", &a, &b, &c, &d) != EOF) {
        ip.ip.arr[0] = a;
        ip.ip.arr[1] = b;
        ip.ip.arr[2] = c;
        ip.ip.arr[3] = d;
        printf("%d\n", ip.num);
    }
    return 0;
}
