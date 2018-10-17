/*************************************************************************
	> File Name: cc.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月06日 星期六 14时49分10秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

typedef int (*func)(int, int);

void EXPECT(int a, int b) {
    if (a == b) {
        printf("----true\n");
    }
}

int just(int a, int b) {
    if (a == b) {
        return 1;
    }
    return 0;
}

int main() {
    func TEST = just;
    if (TEST(1,1)) {
        printf("+++++\n");
    }
    EXPECT(1, 1);
    return 0;
}
