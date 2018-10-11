/*************************************************************************
	> File Name: main.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月07日 星期日 16时45分34秒
 ************************************************************************/

#include <stdio.h>
#include "test.h"
#ifdef TEST_CASE
    #include "testcase1.h"
    #include "testcase2.h"
    //#include "testcase3.h"
#endif

int main() {
    printf("Hello World!\n");
    return RUN_ALL_TEST();
}


