/*************************************************************************
	> File Name: testcase2.h
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月07日 星期日 11时19分22秒
 ************************************************************************/

#ifndef _TESTCASE2_H
#define _TESTCASE2_H
#include "test.h"
#include "add.h"

TEST(test, add) {
    EXPECT(add(1, 2), 3);
    EXPECT(add(3, 4), 7);
    EXPECT(add(2, 2), 4);
}
#endif
