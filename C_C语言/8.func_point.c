/*************************************************************************
	> File Name: 8.func_point.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月06日 星期六 13时12分56秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int add (int a, int b) {
    return a + b;
}

typedef int (*func)(int, int);//func是一个函数指针类型

int main() {
    func func_a = add;
    /*
     删除typedef...
     func...
     int (*func)(int, int) = add; //func仅仅是一个函数指针变量
    */
    printf("%d\n", func_a(4, 5));
    return 0;
}

