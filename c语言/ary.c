/*************************************************************************
	> File Name: ary.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月10日 星期三 23时02分22秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100000000

int a[MAX] = {0};

int main() {
    //int *a;
    //a = (int *)malloc(MAX);
    //memset(a, 0, sizeof(a));
    printf("%d\n", a[MAX - 1]);
    return 0;
}
