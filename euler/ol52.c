/*************************************************************************
	> File Name: ol52.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月16日 星期四 19时57分15秒
 ************************************************************************/

#include<stdio.h>
#include <inttypes.h>
#include <algorithm>
using namespace std;

int get_num(int n, int *b) {
    int temp = 0;
    for (int i = 0; i < n; i++) {
        temp = temp * 10 + b[i];
    }
    return temp;
}
int check(int *b, int n, int64_t num) {
    int bit[10] = {0};
    int temp;
    for (int i = 0; i < n; i++) {
        bit[b[i]] = 1;
    }
    while (num) {
        temp = num % 10;
        if (!bit[temp] && temp != 1) return 0;
        num /= 10;
    }
    return 1;
}
int main() {
    int64_t temp, ans;
    int k;
    int b[10] = {2,3,4,5,6};
    do {
        k = 0;
        temp = get_num(5, b) + 100000;
        for (int i = 2; i <= 6; i++) {
            ans = temp * i;
            if (!check(b, 5, ans)) {
                k = 1;
                break;
            }
        }
        if (k == 0) {
            printf("%"PRId64"\n", temp);
        }
    }while(next_permutation(b, b+5));
    k = 0;
    while (k < 10) {
        int m = 0, p = k;
        for (int i = 2; i <= 6; i++) {
            if (i < p) {
                b[m++] = i;
            } else {
                b[m++] = k;
                p = 9;
                b[m++] = i;
            }
        }
        if (m == 5) b[m++] = k;
        int x;
        do {
            x = 0;
            temp = get_num(m, b) + 1000000;
            for (int i = 2; i <= 6; i++) {
                ans = temp * i;
                if (!check(b, m, ans)) {
                    x = 1;
                    break;
                }
            }
            if (x == 0) {
                printf("%"PRId64"\n", temp);
            }
        }while(next_permutation(b, b+m));
        k++;
 //       printf("%d\n", k);
    }
    return 0;
}
