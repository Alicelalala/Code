/*************************************************************************
	> File Name: 7.point.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月06日 星期六 11时59分54秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <inttypes.h>
using namespace std;

int main() {
    int64_t temp_num;
    int a = 5, *p = &a;
    char b = 'c', *q = &b;
    printf("%d %d\n", a, *p);
    printf("sizeof(*p) = %lu\n", sizeof(p));
    printf("sizeof(*q) = %lu\n", sizeof(q));
    p = (int *)&temp_num;
    q = (char *)&temp_num;
    p[1] = 0x3f80;
    p[0] = 0;
    printf("%"PRIx64"\n", temp_num);
    printf("%d\n", (int)temp_num); //取低8位
    double *p_ = (double *)&temp_num;
    *p_ = 1.0;
    printf("%"PRIx64"\n", temp_num);
    temp_num = 1.0;
    printf("%"PRIx64"\n", temp_num);
    return 0;
}
