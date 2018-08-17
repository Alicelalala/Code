/*************************************************************************
	> File Name: ol43.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年06月06日 星期三 20时22分46秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int prime[10] = {2, 3, 5, 7, 11, 13, 17};
int sum[50] = {0};

bool Sub_string_div(int *num) {
    if (num[0] == 0) return false;
    int Ddd = 0, n, p;
    for (int i = 0; i < 8; i++) {
        n = 3, p = i + 1;
        while (n) {
            Ddd = Ddd * 10 + num[p];
            n--;
        }
        if (Ddd % prime[i]) return false;
    }
    return true;
}

int get_sum(int *num) {
    int len = 0;
    for (int i = 9; i >= 0; i--) {
        sum[len++] += num[i];
        if (sum[len - 1] > 10) {
            sum[len] += sum[len - 1] / 10;
            sum[len - 1] %= 10;
        }
    }
    return len;
}

int main() {
    int num[11];
    int p;
    for (int i = 0; i < 10; i++) {
        num[i] = i;
    }
    do {
        if (Sub_string_div(num)) {
            p = get_sum(num);
        }
    } while (next_permutation(num, num + 10));
    for (int i = p; i >= 0; i--) {
        printf("%d", sum[p]);
    }
    return 0;
}
