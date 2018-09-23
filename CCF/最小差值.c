/*************************************************************************
	> File Name: 最小差值.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年08月23日 星期四 13时46分38秒
 ************************************************************************/

#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int num[n + 5];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    int min = 10000;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            //int temp = abs(num[i] - num[j]);
            //printf("%d\n", temp);
            min = abs(num[i] - num[j]) < min ? abs(num[i] - num[j]) : min;
        }
    }
    printf("%d", min);
    return 0;
}
