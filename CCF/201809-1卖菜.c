/*************************************************************************
	> File Name: 1809-1买菜.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年12月14日 星期五 10时24分06秒
 ************************************************************************/

#include <stdio.h>

#define MAX_N 1000

int main() {
    int n;
    scanf("%d", &n);
    int a[MAX_N + 1], b[MAX_N + 1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    //处理两个特殊点，i=0和i=n-1，因为2 <= n <= 1000，所以以下的角标都有意义
    b[0] = (a[0] + a[1]) / 2;
    b[n - 1] = (a[n - 2] + a[n - 1]) / 2;
    for (int i = 1; i < n - 1; i++) {
        b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3;
    } 
    for (int i = 0; i < n; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", b[i]);
    }

    return 0;
}
