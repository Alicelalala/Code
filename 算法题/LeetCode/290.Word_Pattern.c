/*************************************************************************
	> File Name: 290.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月04日 星期五 14时56分56秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 1000000
#define BASE 'a'
#define BASE_CNT 26
#define BASE 'a'
#define BASE_CNT 26
int wordPattern(char *patter, char *str) {
    int len = strlen(patter);
    int num = 1;
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') num++;
    }
    if (len != num) return 0;
    char *bit[BASE_CNT];
    for (int i = 0; i < BASE_CNT; i++) {
        bit[i] = NULL;
    }
    int j = 0, k = 0;
    for (int i = 0; patter[i]; i++) {
        k = 0;
        char *temp = (char *)malloc(sizeof(char) * strlen(str));
        while (str[j] && str[j] != ' ') temp[k++] = str[j++];
        j++;
        if (bit[patter[i] - BASE] == NULL) {
            for (int m = 0; m < BASE_CNT; m++) {
                if (bit[m] == NULL) continue;
                if (strcmp(bit[m], temp) == 0) return 0;
            }
            bit[patter[i] - BASE] = temp;
        } else {
            if (strcmp(bit[patter[i] - BASE], temp) != 0) return 0;
        }
    }
    return 1;
}

int main() {
    char str1[MAX_N], str2[MAX_N];
    scanf("%s", str1);
    getchar();
    scanf("%[^\n]s", str2);
    getchar();
    printf("%d\n", wordPattern(str1, str2));
    return 0;
}
