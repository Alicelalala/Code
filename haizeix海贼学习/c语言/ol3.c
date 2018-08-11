/*************************************************************************
	> File Name: ol3.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月26日 星期四 09时12分48秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#define MAX 600851475143

int64_t main() {
    int64_t factor = 2;
    int64_t temp = MAX;
    while (temp > 1) {
         while (temp % factor == 0) {
            temp /= factor;
            printf("%ld\t", factor);
        }

        factor += (factor == 2? 1 : 2);
        
    }
    return 0;
}
