/*************************************************************************
	> File Name: 15.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月09日 星期一 20时31分33秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int a[20];
    int *p = &a[0];
    int x;
    int y;
   x = sizeof(p);
   y = sizeof(a);
    printf("%d %d", x, y);
    return 0;

}
