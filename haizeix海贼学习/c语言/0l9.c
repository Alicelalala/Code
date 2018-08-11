/*************************************************************************
	> File Name: 0l9.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月26日 星期四 18时25分58秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int main() {
    int a = 0;
    int temp;

    for (int i = 100; i < 900; ++i) {
        for (int j = 100; j < 900; ++j) {
            temp = sqrt( i * i + j * j);
            if (temp * temp != i * i + j * j) continue;
            if ((i + j + temp) > 1000) break;
            if ((i + j + temp) == 1000) {
                printf("%d\t%d\t%d\t%d", i, j, temp, i * j * temp);
                a = 1;
                break;
            }
        }

        if (a) break;
    }

    return 0;
}

