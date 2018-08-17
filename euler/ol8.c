/*************************************************************************
	> File Name: ol8.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 15时10分35秒
 ************************************************************************/

#include<stdio.h>
#include <inttypes.h>
#include"ol8.h"

int main() {
    int64_t ans = 1, zero = 0, max = 0;
    for (int i = 0; i < 1000; i++) {
        if (num[i] != '0') {
            ans *= (num[i] - '0');
        } else {
            zero++;
        }
        if (i >= 13) {
            if (num[i - 13] != '0') {
                ans /= (num[i - 13] - '0');
            } else {
                zero--;
            }
        }
        if (zero == 0 && ans > max) max = ans;
    }
    printf("%"PRId64"\n", max);
}
