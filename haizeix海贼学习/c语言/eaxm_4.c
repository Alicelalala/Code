/*************************************************************************
	> File Name: eaxm_4.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月10日 星期四 23时09分57秒
 ************************************************************************/

#include <stdio.h>

int num[10] = {0};

void g(int x, int y) {
    int detal = 1, n = 0, p = x;
    for (int i = 1; i < x; i++) {
        detal *= i;
    }
    int temp = y - 1;
    int rank;
    while (temp) {
        rank = temp / detal + 1;
        for (int i = 1; i <= x; i++) {
            if (!num[i]) n++;
            if (n == rank) {
                printf("%d", i);
                n = 0;
                num[i] = 1;
                break;
            }
        }
        temp %= detal;
        detal /= --p;
    }
    for (int i = 1; i <= x; i++) {
        if (!num[i]) printf("%d", i);
    }
    return ;
}
int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    g(x, y);
    
    return 0;
}

