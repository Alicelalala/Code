/*************************************************************************
	> File Name: testcase2.h
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月07日 星期日 20时20分22秒
 ************************************************************************/

#ifndef _TESTCASE2_H
#define _TESTCASE2_H
#include "test.h"
#include "dicsearch.h"

TEST(test, dicsearch) {
    EXPECT(bisection(3, -3, ff));
    EXPECT(bisection(6, 7, ff));
}

#endif
