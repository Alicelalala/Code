/*************************************************************************
	> File Name: ol19_game.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月06日 星期一 17时39分06秒
 ************************************************************************/

#include <stdio.h>

int get_Weekday(int y, int m, int d) {
    int w;
    if (m == 1 || m == 2) {
        y--;
        m += 12;
    }
    w = (d + 2 * m + (m + 1) * 3 / 5 
        + y + (y / 4) - (y / 100) + (y / 400)) % 7;
    return w;
}
int main() {
    int sum = 0;
    for (int i = 1901; i <= 2000; i++) {
        for (int j = 1; j <= 12; j++) {
            if (get_Weekday(i, j, 1) == 6) {
                sum += 1;
                printf("%d\t%d\n", i, j);
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}
