/*************************************************************************
	> File Name: 13.Roman_to_integer.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月02日 星期三 12时43分43秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int romanToInt(char *s) {
    int num[128];
    num['I'] = 1; num['V'] = 5; num['X'] = 10; num['L'] = 50;
    num['C'] = 100; num['D'] = 500; num['M'] = 1000;
    int len = strlen(s);
    int n = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (i == len - 1) {n += num[s[i]]; continue;}
        if (num[s[i]] < num[s[i + 1]]) {
            n -= num[s[i]];
        } else {
            n += num[s[i]];
        }
    }
    return n;
}

int main() {
    char str[1024];
    scanf("%s", str);
    printf("%d\n", romanToInt(str));
    return 0;
}
