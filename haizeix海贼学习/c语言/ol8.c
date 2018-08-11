/*************************************************************************
	> File Name: ol8.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月09日 星期三 13时11分47秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include "8.h"

int main() {
    int64_t zero = 0, ans = 1, maxN = 0;
    for (int32_t i = 0; i < 1000; ++i) {
        if (a[i] != '0') {
            ans *= a[i] - '0';
        } else {
            zero++;
        }
        if (i >= 13) {
            if (a[i - 13] != '0') {
                ans /= a[i - 13] - '0';
            } else {
                zero--;
            }
        }
        if (zero == 0 && ans > maxN) maxN = ans;
    }
    printf("%"PRId64"\n", maxN);
    return 0;
}

