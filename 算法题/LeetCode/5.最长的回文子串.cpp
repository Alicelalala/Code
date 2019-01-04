/*************************************************************************
	> File Name: 5.最长的回文子串.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月01日 星期二 16时57分47秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 3000

int getmidlen (char *temp, int mid, int ans) {
    int len = 0;
    if (!mid) return 0;
    int i = 1;
    while (i <= ans) {
        if (temp[mid - i] != temp[mid + i]) break;
        len++;
        i++;
    }
    return len;
}

char * longestPalindrome (char *s) {
    int p[MAX_N + 5], k = 0;
    char temp[MAX_N];
    for (int i = 0; s[i]; i++) {
        temp[k++] = '#';
        temp[k++] = s[i];
    }
    temp[k] = '#';
    int len = k + 1, max = 0, pos;
    for (int i = 0; i < len; i++) {
        int ans = (i > len - i - 1) ? len - i - 1 : i;
        p[i] = getmidlen(temp, i, ans);
        if (p[i] > max) {
            max = p[i];
            pos = i;
        }
    }
    char *palind = (char *)malloc(sizeof(char) * (max * 2));
    int ind = 0;
    for (int i = pos - max; i <= pos + max; i++) {
        if (temp[i] == '#') continue;
        palind[ind++] = temp[i];
    }
    palind[ind] = '\0';
    return palind;
}

int main () {
    char str[MAX_N + 5];
    scanf("%s", str);
    printf("%s\n", longestPalindrome(str));
    return 0;
}
