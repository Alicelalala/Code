/*************************************************************************
	> File Name: scanf_test.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年12月29日 星期六 10时44分28秒
 ************************************************************************/

#include <stdio.h>

int main() {
    char str[1024];
    while (scanf("%[^\n]", str)) {
        printf("%s", str);
    }
    printf("\n");
    return 0;
}
