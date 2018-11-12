/*************************************************************************
	> File Name: 20.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月22日 星期一 22时41分15秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char pipei (char a) {
    switch (a) {
        case '{': return '}';
        case '[': return ']';
        case '(': return ')';
    }
}

int main() {
    int flag = 1;
    char buffer[50];
    scanf("%s", buffer);
    int len = strlen(buffer);
    char *ans = (char *)malloc(sizeof(char) * 50);
    int n = 0;
    for (int i = 0; i < len; i++) {
        switch (buffer[i]) {
            case '{': ans[n++] = '{'; break;
            case '[': ans[n++] = '['; break;
            case '(': ans[n++] = '('; break;
            case '}':
            case ']':
            case ')': {
                if (pipei(ans[n - 1]) == buffer[i]) {
                    n--;
                } else {
                    flag = 0;
                    printf("false\n");
                    break;
                }
            }
        }
    }
    if (flag == 1) {
        printf("true\n");
    }
    return 0;
}
