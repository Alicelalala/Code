/*************************************************************************
	> File Name: 125.Valid_Palindrome.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月02日 星期三 16时49分58秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

void simples(char *s) {
    int k = 0;
    //printf("%d\n", strlen(s));
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') s[k++] = s[i] + 32;
        else if (s[i] < 'a' && s[i] > 'z') continue;
        else s[k++] = s[i];
    }
    s[k] = '\0';
}

int isPalindrome(char* s) {
    simples(s);
    printf("%s\n", s);
    return 0;
}

int main() {
    char str[1024];
    scanf("%[^\n]s", str);
    getchar();
    int len = isPalindrome(str);
}

