/*************************************************************************
	> File Name: ol12.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月26日 星期四 20时40分38秒
 ************************************************************************/

#include <stdio.h> 
#include <math.h>
#define MAX 150001

int prime[MAX];
int ans[MAX + 5] = {0};

void get_prime() {
    int num = 0;
    for (int i = 2; i <= MAX; ++i) {
        if (!ans[i]) prime[num++] = i;
        for (int j = 0; j < num; ++j) {
            if (i * prime[j] > MAX) break;
            ans[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int Trig(int n) {
    int temp = n;
    int lim = sqrt(temp);
    int res;

    while (temp > 1) {
         res = 1;
        
        for (int i = 0; i <= lim; ++i) {
            int num = 0;
            while (temp % prime[i] == 0) {
                temp /= prime[i];
                num++;
            }
            res *= num + 1;
        }
    }

    return res;
}

int main() {
    int temp;
    int num;
    
    get_prime();

    for (int n = 300; n < MAX; ++n) {
        temp = (1 + n) * n / 2;
        num = Trig(temp);
        if (num >= 500) {
            printf("%d\n", temp);
            break;
        }
    }

    return 0;

}
