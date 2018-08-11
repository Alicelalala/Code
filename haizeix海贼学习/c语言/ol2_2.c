/*************************************************************************
	> File Name: ol2_2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月26日 星期四 00时36分23秒
 ************************************************************************/

#include <stdio.h> 
#define MAX 4000000

void main() {
    unsigned long long sum = 0;
    unsigned int x = 0, y = 1, z = 0, count = 0, count_num = 0;
    while(z <= MAX) {
        z = x + y;
        if (z % 2 == 0) {
            sum += z;
            count_num++;
        }
        count++;
        x = y; y = z;
    }

    printf("%d\t %lld",count_num, sum);
}
