/*************************************************************************
	> File Name: ol15.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月27日 星期五 23时42分13秒
 ************************************************************************/

#include <stdio.h>
#define grid 2

int main() {
    int sum = 0;
    int temp = grid;

    for (int i = 1; i <= grid + 1; i++) {
        sum += i * (temp + 1);
        temp -= 1;
    }

    printf("%d", sum);
    return 0;
}

