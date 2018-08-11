/*************************************************************************
	> File Name: LX_prime.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月23日 星期一 17时08分20秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#define MAX 400000
#define MAXL 400000
int main() {
    int ans[MAXL] = {0};
    int prime[MAX];
    int i, j;
    int count = 0;
    ans[0] = ans[1] = 1;

    for (i = 2; i <= MAX; ++i) {
        if (!ans[i]) {
            prime[count++] = i;
        }
        for (j = 0; j < count; ++j) {
            if (i * prime[j] > MAX) {
                break;
            }
            ans[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }

    printf("%d", prime[2000]);

    return 0;
}

