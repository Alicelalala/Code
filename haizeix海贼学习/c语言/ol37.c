/*************************************************************************
	> File Name: ol37.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月25日 星期三 18时38分07秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAXL 1000000
#define MAXN 2500000

int ans[MAXN] = {0};

int is_circular(int x) {
    int digits = floor(log10(x));
    int digit_value = pow(10, digits);
    if (digits == 0) return 0;
    int  temp = x;
    for (int i = 0; i < digits; ++i) {
        
        temp = temp % digit_value;
        if (ans[temp] == 1) return 0;
        digit_value /= 10;
    }

    temp = x;
    for (int i = 0; i < digits; ++i) {
        temp = temp / 10;
        if (ans[temp] == 1) return 0;
    }
    return 1;
}

int main() {
    int prime[MAXL];
    ans[0] = ans[1] = 1;

    int num = 0, count = 0;

    for (int i = 2; i <= MAXL; i++) {
        if (!ans[i]) {
            prime[num++] = i;
        }
            for (int j = 0; j < num; j++) {
                if (i * prime[j] > MAXL)     break;
                
                ans[i * prime[j]] = 1;
                if (i % prime[j] == 0)     break;
                
            }
        
    }

    int sum = 0;

    for (int i = 0; i < num; ++i) {
        if (is_circular(prime[i])) {
             printf("%d\t", prime[i]);
            sum += prime[i];
        }
    }
    printf("%d\n", sum);
    return 0;

}

