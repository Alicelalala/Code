/*************************************************************************
	> File Name: ol42.c
	> Author: 
	> Mail: 
	> Created Time: 2018年06月06日 星期三 20时05分05秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#include "042.h"

bool isTriangleNumber(int32_t n) {
    int32_t m = (int32_t) floor(sqrt(n * 2));
    return m * (m + 1) / 2 == n;
}

int32_t main() {
    int32_t i = 0, sum = 0, total = 0;
    while (wordList[i].length() != 0) {
        sum = 0;
        for (int32_t j = 0; j < wordList[i].length(); j++) {
            sum += wordList[i][j] - 'A' + 1;
        }
        if (isTriangleNumber(sum)) ++total;
        ++i;
    }
    printf("%d\n", total);
    return 0;
}

