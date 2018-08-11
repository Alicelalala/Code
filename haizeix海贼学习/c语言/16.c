/*************************************************************************
	> File Name: 16.c	> Author: 
	> Mail: 
	> Created Time: 2018年04月11日 星期三 20时32分20秒
 ************************************************************************/

#include<stdio.h>
#define MAX(a, b) ({\
                   ypeof(a) temp_a = a;\
                   ypeof(b) temp_b = b;\
                    (temp_a) > (temp_b) ? ((temp_a) : (temp_b);\
                                          })

int main() {
    int a = 7;

    printf("%d\n", MAX(2, 3));
    printf("%d\n", (5 + MAX(2, 3)));
    printf("%d\n", MAX(2, MAX(3, 4)));
    printf("%d\n", MAX(2, 3 > 4 ? 3 : 4));
    printf("%d\n", MAX(a++, 6));

    return 0;
}
