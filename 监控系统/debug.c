/*************************************************************************
	> File Name: debug.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年12月23日 星期日 15时32分09秒
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h> 
#include <stdio.h>
#define DEBUGLL(format, ...) printf (format, ##__VA_ARGS__)

int main() {
    DEBUGLL("hello, %d, %d\n", 23, 45);
    return 0;
}
