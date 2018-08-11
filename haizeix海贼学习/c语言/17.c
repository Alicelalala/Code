/*************************************************************************
	> File Name: 17.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月22日 星期日 16时13分26秒
 ************************************************************************/

#include<stdio.h>
#include <inttypes.h>
#define  MAX 1000000

int get_len(int64_t n) {
    if (n == 1) {
        return 1;
    }
    else if (n % 2 == 0) {
        return get_len(n / 2) + 1;
    }
    else {
        return get_len(n * 3 + 1) + 1;
    }
}

int main() {
    int64_t n;
    int temp;
    int p;
    int ans = 0;
    for(n = 1; n < MAX; n++) {
        temp = get_len(n);
        if (temp > ans) {
            ans = temp;
            p = n;
        }
    }

    printf("%d %d", ans, p);
    return 0;

}
