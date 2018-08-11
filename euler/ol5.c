/*************************************************************************
	> File Name: ol5.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 14时27分30秒
 ************************************************************************/

#include<stdio.h>
#include <inttypes.h>

int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a % b);
}
int main() {
    int64_t ans = 1;
    for (int i = 1; i <= 20; i++) {
        ans *= i / gcd(i, ans);
    }
    printf("%"PRId64"\n", ans);
    return 0;
}
