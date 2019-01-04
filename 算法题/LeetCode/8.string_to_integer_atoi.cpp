/*************************************************************************
	> File Name: 8.string_to_integer_atoi.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月02日 星期三 10时25分46秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#define MAX_N 1024

int myAtoi(char *str) {
    int i = 0, j = 0;
    while(str[i] == ' ') i++;
    int num = 1;
    if (str[i] == '\n') return 0;
    if (str[i] == '-') i++, num = -1;
    else if (str[i] < '0' && str[i] > '9') return 0;
    char temp[MAX_N] = ""; //注意初始化
    while (str[i] >= '0' && str[i] <= '9') temp[j++] = str[i], i++;
    if (j > 10 ) return num == -1 ? INT32_MIN : INT32_MAX;
    //printf("%s\n", temp);
    //printf("%d\n", strcmp(temp, "2147483647"));
    if (j == 10 && (strcmp(temp, "2147483647")) > 0)
        return num == -1 ? INT32_MIN : INT32_MAX;
    int k = 0, x = 0;
    while (k < j) {
        x = x * 10 + (temp[k] - '0');
        k++;
    }
    return x * num;
}

int main() {
    char str[MAX_N];
    scanf("%[^\n]s", str);
    getchar();
    int num = myAtoi(str);
    printf("%d\n", num);
    //printf("%d\n", strcmp("2147483647", "2147483647"));
    return 0;
}
