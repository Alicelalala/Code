/*************************************************************************
	> File Name: u_1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月13日 星期日 15时42分56秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

struct Node {
    char a;
    int b;
    char c;
    uint16_t d;
    char e;
};

#define offset(T, name) (int) (int64_t)(&(((T *)(NULL)) -> name))


int main() {
    printf("%d\n", offset(struct Node, a));
    printf("%d\n", offset(struct Node, b));
    printf("%d\n", offset(struct Node, c));
    printf("%d\n", offset(struct Node, d));
    return 0;
}
