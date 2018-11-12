/*************************************************************************
	> File Name: 8.luogu1054.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月22日 星期一 14时14分55秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

#define INF 0x3f3f3f3f
#define MOD 100000007

int check (char buffer[]) {
    int len = strlen(buffer);
    for (int i = 0; i < len; i++) {
        switch(buffer[i]) {
            case '(': {
                if (i != 0) {
                    if (buffer[i - 1])
                }
            } break;
            case ')': {
                    
            }
            case '+':
            case '-':
            case '*':
            case '^': {
                
            }
        }
    }
}

int power (int a, int b) {
    int ret = 1;
    while (b--) {
        ret *= a;
        ret %= MOD;
    }
    return ret;
}

int calc (char str[], int l, int r, int value) {
    int pos = -1, temp_prior = 0, prior = INF - 1;
    for (int i = l; i <= r; i++) {
        int cur_prior = INF;
        switch (str[i]) {
            case '(': temp_prior += 100; break;
            case ')': temp_prior -= 100; break;
            case '+': cur_prior = temp_prior + 1; break;
            case '-': cur_prior = temp_prior + 1; break;
            case '*': cur_prior = temp_prior + 2; break;
            case '^': cur_prior = temp_prior + 3; break;
        }
        if (cur_prior <= prior) {
            prior = cur_prior;
            pos = i;
        }
    }
    if (pos == -1) {
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (str[i] == 'a') {
                num = num * 10 + value;
                num %= MOD;
            }
            if (str[i] < '0' || str[i] > '9') continue;
            num = num * 10 + str[i] - '0';
            num %= MOD;
        }
        return num;
    } else {
        int a = calc(str, l, pos - 1, value);
        int b = calc(str, pos + 1, r, value);
        switch (str[pos]) {
            case '+': return (a + b) % MOD;
            case '-': return (a - b + MOD) % MOD;
            case '*': return (a * b) % MOD;
            case '^': return power(a, b);
        }
    }
    return 0;
}

int main() {
    char buffer[60], buf[60];
    int len_b, n, ans = 0;
    int flag[30] = {0};
    while (scanf("%[^\n]s", buffer));
    //if (!check(buffer)) return 0;
    printf("%d\n", check(buffer));
    len_b = strlen(buffer);
    scanf("%d", &n);
    getchar();
       while (scanf("%[^\n]s", buf) != EOF) {
            getchar();
           if (!check(buf)) continue;
            int len = strlen(buf);
            int a, b, value;
            
            for (int k = 0; k < 5; k++) {
                value = rand() % 10 + 1;
                a = calc(buffer, 0, len_b - 1, value);
                b = calc(buf, 0, len - 1, value);
                //printf("%d %d %d\n", value, a, b);
                if (a != b) {
                    flag[ans] = 1;
                    break;
                }
            }
            ans++;
            if (ans == n) break;
        }
        for (int i = 0; i < n; i++) {
            if (flag[i] == 0) {
                printf("%c", 'A' + i);
            }
        }
        printf("\n");
    return 0;
}

