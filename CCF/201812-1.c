/*************************************************************************
	> File Name: 201912-1.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月14日 星期一 15时45分36秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int r, y, g, n, k, t;
    scanf("%d%d%d", &r, &y, &g);
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &k, &t);
        if (k == 2) sum += t + r;
        else if (k != 3) sum += t;
    }
    printf("%d\n", sum);
    return 0;
}
