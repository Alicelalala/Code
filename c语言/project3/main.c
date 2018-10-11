/*************************************************************************
	> File Name: main.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月07日 星期日 11时16分26秒
 ************************************************************************/

#include <stdio.h>
//#include "is_prime.h"
//#include "add.h"
#include "test.h"
#ifdef TEST_CASE
    #include "testcase1.h"
    #include "testcase2.h"
#endif

int main() {
    printf("Hello World!\n");
    return RUN_ALL_TEST();
}
