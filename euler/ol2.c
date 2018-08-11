/*************************************************************************
	> File Name: ol2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 11时00分06秒
 ************************************************************************/

#include<stdio.h>
#include <inttypes.h>

#define Max 4000000

int main() {
    int f0 = 0, f1 = 1;
    int f = 0, sum = 0;
    while (f <= Max) {
        f = f0 + f1;
        f0 = f1;
        f1 = f;
        if (f % 2 == 0) {
            sum += f;
        }
    }
    printf("%d", sum);
    return 0;
}

