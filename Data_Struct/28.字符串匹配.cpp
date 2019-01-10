/*************************************************************************
	> File Name: 27.字符串匹配.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年12月30日 星期日 19时43分40秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define TEST(func, a, b) { \
    printf("%s(\"%s\", \"%s\") = %d\n", #func, a, b, func(a, b)); \
}

int bruteForce(char *str, char *pattern) {
    for (int i = 0; str[i]; i++) {
        int flag = 1;
        for (int j = 0; pattern[j]; j++) {
            if (str[i + j] == pattern[j]) continue;
            flag = 0;
            break;
        }
        if (flag) return i;
    }
    return -1;
}

int KMP(char *str, char *pattern) {
    int *next = (int *)malloc(sizeof(int) * strlen(pattern));
    next[0] = -1;
    for (int i = 1; pattern[i]; i++) {
        int j = next[i - 1];
        while (j != -1 && pattern[j + 1] != pattern[i]) j = next[j];
        if (pattern[j + 1] == pattern[i]) next[i] = j + 1;
        else next[i] = -1;
    }
    int i = 0, j = -1;
    while (str[i])  {
        while (j != -1 && str[i] != pattern[j + 1]) j = next[j];
        if (str[i] == pattern[j + 1]) {
            j++;
        }
        i++;
        if (pattern[j + 1] == 0) return i - strlen(pattern);
    }
    return -1;
}

int Sunday(char *str, char *pattern) {
    #define BASE 128
    int ind[BASE] = {0};
    int len = strlen(pattern), max_len = strlen(str);
    for (int i = 0; i < BASE; i++) {
        ind[i] = len + 1;
    }
    for (int i = 0; i < len; i++) {
        ind[pattern[i]] = len - i;
    }
    for (int i = 0; i < max_len;) {
        int flag = 1;
        for (int j = 0; j < len; j++) {
            if (str[i + j] == pattern[j]) continue;
            i += ind[str[i + len]];
            flag = 0;
            break;
        }
        if (flag) return i;
    }
    return -1;
}

int shiftAnd(char *str, char *pattern) {
    #define BASE 128 
    int code[BASE] = {0}, len = 0;
    for (len = 0; pattern[len]; len++) {
        code[pattern[len]] |= (1 << len);
    }
    int p = 0;
    for (int i = 0; str[i]; i++) {
        p = (p << 1 | 1) & code[str[i]];
        if (p & (1 << (len - 1))) return i - len + 1;
    }
    return -1;
    #undef BASE 
}

int longShiftAnd(char *str, char *pattern) {
    #define BASE 128
    #define MAX_N 1000
    int code[BASE][MAX_N] = {0}, len = 0, k = 0;
    for (len = 0; pattern[len]; len++) {
        if (len && len % 32 == 0) k++;
        code[pattern[len]][k] |= (1 << (len % 32));
    }
    int p[MAX_N] = {0}, l = 0;
    for (int i = 0; str[i]; i++) {
        for (int j = 0; j <= l; j++) {
            if (p[j] & (1 << 31)) {
                p[j] = p[j] & ((int)pow(2, 31) - 1);
                p[j + 1] = 1;
                l++;
            }
            p[j] = (p[j] << 1 | 1) & code[str[i]][j];
        }
        if (p[(len - 1) / 32] & (1 << ((len - 1) % 32))) return i - len + 1;
    }
    return -1;
}

int main() {
    char str[100], pattern[300];
    while (scanf("%s%s", str, pattern) != EOF) {
        TEST(bruteForce, str, pattern);
        TEST(KMP, str, pattern);
        TEST(shiftAnd, str, pattern);
        TEST(longShiftAnd, str, pattern);
    }
    return 0;
}
