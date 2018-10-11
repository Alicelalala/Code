/*************************************************************************
	> File Name: test.h
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月07日 星期日 13时09分56秒
 ************************************************************************/

#include <stdio.h>
#include "test.h"

static FuncData *FuncData_head = NULL;

void addFuncData(
    const char *a,
    const char *b,
    test_func_t func
) {
    FuncData *p = (FuncData *)malloc(sizeof(FuncData));
    p->a_str = a;
    p->b_str = b;
    p->func = func;
    p->next = FuncData_head;
    FuncData_head = p;
    return ;
}

int RUN_ALL_TEST() {
    FuncData ret;
    ret.next = NULL;
    for (FuncData *p = FuncData_head, *q; p; p = q) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;    
    }
    FuncData_head = ret.next;
    for (FuncData *p = FuncData_head; p; p = p->next) {
        struct TestFuncData data = {0, 0};
        printf("[%s %s]\n", p->a_str, p->b_str);
        p->func(&data);
    }
    return 0;
}
