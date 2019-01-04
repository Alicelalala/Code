/*************************************************************************
	> File Name: 242.Valid_Anagram.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月02日 星期三 20时34分15秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX_N 1000000
#define BASE 'a'

int isAnagram(char *s, char *t) {
    if (strlen(s) != strlen(t)) return 0;
    int bitS[128] = {0}, bitT[128] = {0};
    for (int i = 0; s[i]; i++) {
        bitS[s[i] - BASE] += 1;
    }
    for (int i = 0; t[i]; i++) {
        bitT[t[i] - BASE] += 1;
    }
    for (int i = 0; i < 128; i++) {
        if (bitS[i] != bitT[i]) return 0;
    }
    return 1;
}

int main() {
    char str1[MAX_N], str2[MAX_N];
    scanf("%s%s", str1, str2);
    printf("%d\n", isAnagram(str1, str2));
    return 0;
}
