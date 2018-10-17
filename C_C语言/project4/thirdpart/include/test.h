/*************************************************************************
	> File Name: test.h
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月07日 星期日 13时09分56秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H
#include <stdlib.h>

struct TestFuncData {
    int total, expand;
};

typedef void (*test_func_t)();
typedef struct FuncData {
    const char *a_str, *b_str;
    test_func_t func;
    struct FuncData *next;
} FuncData;

void addFuncData(
    const char *a,
    const char *b,
    test_func_t func;
);

#define TEST(a, b) \
    void a##_haizeix_##b(); \
    __attribute__((constructor)) \
    void ADDFUNC_##a##_haizeix_##b() { \
    addFuncData(#a, #b, a##_haizeix_##b);\
    } \
    void a##_haizeix_##b(struct TestFuncData *__data)

#define EXPECT(a) ({ \
    printf("该函数x的结果是：%d 是%s\n", a, a  == 0 ? "False" : "TRUE");\
})

int RUN_ALL_TEST();

#endif
