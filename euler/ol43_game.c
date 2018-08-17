/*************************************************************************
	> File Name: ol43_game.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月06日 星期一 15时19分57秒
 ************************************************************************/

#include <stdio.h>
#include <algorithm>
#include <inttypes.h>
using namespace std;

#define BASE 10

int num[] = {0,1,2,3,4,5,6,7,8,9};

int64_t check(int *num) {
    int init_prime[7] = {2,3,5,7,11,13,17};
    if (num[0] == 0) return 0;
    int64_t x = num[0], ans = num[0];
    int j = 0;
    for (int i = 1; i < BASE; i++) {
        x =  x * 10 + num[i];
        ans = ans * 10 + num[i];
        if (i >= 3) {
            x = x - 1000 * num[i - 3];
            if (x % init_prime[j++]) return 0;
        }
    }
    return ans;
}
int main() {
    int64_t sum = 0;
    do {
        int64_t temp = check(num);
        if (temp){
            printf("%"PRId64"\n", temp);
            sum += temp;
        }
    } while (next_permutation(num, num + 10));
    printf("%"PRId64"\n", sum);
    return 0;
}

