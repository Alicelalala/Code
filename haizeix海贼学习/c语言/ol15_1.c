/*************************************************************************
	> File Name: ol15_1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月01日 星期二 15时25分59秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>


int main() {
    int64_t mult1 = 1;
    int64_t mult2 = 1;
    
    for (int i = 21; i <= 40; i++) {
        mult1 *= i;
        if (mult1 % mult2 == 0) {
            mult1 = mult1 / mult2;
            mult2++;
        }
    }
    while (mult2 <= 20) {
        mult1 /= mult2;
        mult2++;
    }
    
    printf("%"PRId64"\n", mult1);
    return 0;
}

