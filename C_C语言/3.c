/*************************************************************************
	> File Name: 3.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月18日 星期二 20时53分12秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    int ans = 0;
    scanf("%d", &n);
    do {
        n /= 10;
        ans++;
    } while (n);
    printf("%d\n", ans);
    return 0;
}
