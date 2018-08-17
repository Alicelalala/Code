/*************************************************************************
	> File Name: ol28.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 12时46分20秒
 ************************************************************************/

#include<stdio.h>
#include <inttypes.h>

int main() {
    int32_t sum = 1;
    int n = 3;
    while (n <= 1001) {
        sum += 4 * n * n - 6 * n + 6;
        n += 2;
    }
    printf("%"PRId32"\n", sum);
    return 0;
}
