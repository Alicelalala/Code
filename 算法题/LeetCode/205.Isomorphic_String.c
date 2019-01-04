/*************************************************************************
	> File Name: 205.Isomorphic_String.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月02日 星期三 19时22分55秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 1000000
#define BASE ' '
#define CHARL 128 
int isIsomorphic(char *s, char *t) {
    int bit[500] = {0}, tt[500] = {0};
    for (int i = 0; s[i]; i++) {
        if (bit[s[i] - BASE + CHARL] == 0) {
            if (tt[t[i] - BASE + CHARL]) return 0;
            bit[s[i] - BASE + CHARL] = t[i] - BASE + CHARL;
            tt[t[i] - BASE + CHARL] = 1;
        } else if (bit[s[i] - BASE + CHARL] != (t[i] - BASE + CHARL)) return 0;
    }
    return 1;
}

int main() {
    char str1[MAX_N], str2[MAX_N];
    scanf("%s%s", str1, str2);
    printf("%d\n", isIsomorphic(str1, str2));
    return 0;
}
