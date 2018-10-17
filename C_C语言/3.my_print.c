/*************************************************************************
	> File Name: 3.my_print.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月20日 星期四 20时28分03秒
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>

void my_printD(int64_t n);
void printNum(int64_t n);

int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    for (int i = 0, cnt = 0; frm[i]; i++, cnt++) {
        switch (frm[i]) {
            case '%' : {
                i++;
                switch(frm[i]) {
                    case 'd' : {
                        int temp = va_arg(arg, int64_t);
                       my_printD(temp);

                    } break;
                    default : 
                    fprintf(stderr, "error : unknow %%%c\n", frm[i]);
                }
            } break;
            default:
            putchar(frm[i]);
        }
    }
    return cnt;
}

void printNum (int64_t temp) {
    if (temp == 0) return;
    printNum(temp / 10);
    putchar(temp % 10 + '0');
}

void my_printD (int64_t temp) {
    if (temp < 0) {
        putchar('-');
        temp = -temp;
    }
    if (temp == 0) {
        putchar('0');
    } else {
        printNum(temp);
    }
}

int main() {
    int n = 123;
    my_printf("hello world\n");
    my_printf("n = %d\n", n);
    my_printf("n = %d\n", 12000);
    my_printf("n = %d, = %d\n", -567, 345);
    my_printf("n = %d\n", INT32_MIN);
    my_printf("n = %d\n", INT32_MAX);
    return 0;
}
