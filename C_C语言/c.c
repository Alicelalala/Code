/*************************************************************************
	> File Name: c.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月06日 星期六 20时02分52秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include "test.h"
//define loop(i, j) printf("[%s, %s]\n", #i, #j);

int main() {
    TEST(test, is_prime_func) {
        EXPECT(1, 1);
        EXPECT(2, 7);
    }
    return 0;
}
