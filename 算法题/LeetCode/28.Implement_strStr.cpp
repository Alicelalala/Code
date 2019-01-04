/*************************************************************************
	> File Name: 28.Implement_strStr.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月02日 星期三 14时32分38秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    if (strlen(needle) == 0) return 0;
    int next[1000000];
    next[0] = -1;
    for (int i = 1; needle[i]; i++) {
        int j = next[i - 1];
        while (j != -1 && needle[j + 1] != needle[i]) j = next[j];
        if (needle[j + 1] == needle[i]) next[i] = j + 1;
        else next[i] = -1;
    }
    int j = -1;
    for (int i = 0; haystack[i]; i++) {
        while (j != -1 && needle[j + 1] != haystack[i]) j = next[j];
        if (needle[j + 1] == haystack[i]) {
            j++;
        }
        if (j != -1 && !needle[j + 1]) return i - strlen(needle) + 1;
    }
    return -1;
}


int main() {
    char str[1024], needle[1024];
    scanf("%s%s", str, needle);
    printf("%d\n", strStr(str, needle));
    return 0;
}
