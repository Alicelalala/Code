/*************************************************************************
	> File Name: test.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月04日 星期五 13时19分13秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str1 = (char *)malloc(sizeof(char) * 5);
    char *str2 = (char *)malloc(sizeof(char) * 5);
    strcpy(str1, "cd");
    strcpy(str2, "be");
    int n = atoi(str1);
    printf("%d\n", n);
    printf("%d\n", atoi(str2));
    return 0;
}

