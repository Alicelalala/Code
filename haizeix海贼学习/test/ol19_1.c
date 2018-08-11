/*************************************************************************
	> File Name: ol19_1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月07日 星期二 09时42分51秒
 ************************************************************************/

#include <stdio.h>

int get_weekday(int y, int m, int d) {
    if (m == 1 || m == 2) {
        y--;
        m += 12;
    }
    int w;
    w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    return w;
}

int main() {
    int sum  = 0;
    for (int i = 1901; i <= 2000; i++) {
        for (int j = 1; j <= 12; j++) {
            if (get_weekday(i, j, 1) == 6) {
                sum += 1;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}
