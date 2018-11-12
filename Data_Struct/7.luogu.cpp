//洛谷1981
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 2300000
#define MOD 10000

char str[MAXN];

int calc(char *str) {
    int len = strlen(str);
    //printf("%d %d\n", strlen(str+0), strlen(str+1));
    for (int i = 0; str[i]; i++) str[i] = (str[i] == '+'? 0 : str[i]);//?
    //printf("%d %d\n", strlen(str+0), strlen(str+1));
    int total = 0;
    for (int j = 0; j < len; j += strlen(str + j) + 1) {
        //printf("%d \n", strlen(str + j));
        int num = 0, p = 1;
        for (int i = j; str[i]; i++) {
            switch (str[i]) {
                case '*': p *= num; p %= MOD; num = 0; break;
                default : num = num * 10 + str[i] - '0'; 
            }
        }
        p *= num;//不是乘号要再乘上num
        p %= MOD;
        total += p;
        total %= MOD;
    }
    return total;
}
int main () {
    scanf("%s", str);
    printf("%d\n",calc(str));
    return 0;
 }
