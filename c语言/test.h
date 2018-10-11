/*************************************************************************
	> File Name: cao.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月06日 星期六 18时42分34秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#ifndef _TEST_H
#define _TEST_H

struct TestFuncData {
    int total, expand;
};

typedef void (*test_func_t)();
typedef struct FuncData {
    const char *a_str, *b_str;
    test_func_t func;
    struct FuncData *next;
}FuncData;

FuncData *FuncData_head = NULL;

FuncData *getFuncData (
    const char *a, 
    const char *b, 
    test_func_t func, 
    FuncData *next
) {
    FuncData *p = (FuncData *)malloc(sizeof(FuncData));
    p->a_str = a;
    p->b_str = b;
    p->func = func;
    p->next = next;
    return p;
}

#define TEST(a, b) \
    void a##_haizeix_##b();\
    __attribute__((constructor))\
    void ADDFUNC_##a##_haizeix_##b() {\
        FuncData_head = getFuncData(#a, #b, a##_haizex_##b, FuncData_head);\
    } \
    void a##_haizeix_##b(struct TestFuncData *__data)

#define EXPECT(a, b) ({\
    int temp;\
    printf("%s == %s %s\n", #a, #b, (temp = (a == b)) ? "True" : "False");\
    __data->total += 1;\
    __data->expand += temp; \
})

int RUN_ALL_TEST() {
    FuncData ret;
    ret.next = NULL;
    for (FuncData *p = FuncData_head, *q; p; p = q) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
    }
    FuncData_head = ret.next;
    char color[3][100] = {
        "[ \033[1:32m%.2lf%% \033[0m] total ]"
        "[ \033[0:31m%.2lf%% \033[0m]"
        "[ \033[1:31m%.2lf%% \033[0m ]]"
    };
    for (FuncData *p = FuncData_head; p; p = p->next) {
        struct TestFuncData data = {0, 0};
        printf("[%s, %s]\n", p->a_str, p->b_str);
        p->func(&data);
        double rate = 1.0 * data.expand / data.total * 100;
        int ind = 0;
        if (rate < 100) ind = 1;
        if (rate < 50) ind = 2;
        printf(color[ind], 1.0 * data.expand / data.total * 100);
        printf("total : %d expand_cnt : %d\n", data.total, data.expand);
    }
    return 0;
}

#define EXPECT(is_prime_num, num) {\
    printf("%s == %s %s\n", #is_prime_num, #num, is_prime_num == num ? "True" : "False");\
}

#endif
