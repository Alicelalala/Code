/*************************************************************************
	> File Name: testcase1.h
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月07日 星期日 19时00分52秒
 ************************************************************************/

#ifndef _TESTCASE1_H
#define _TESTCASE1_H
#include "test.h"
#include "newton.h"

TEST(test, newton) {
    EXPECT(newton(f, f_prime));
}

#endif
