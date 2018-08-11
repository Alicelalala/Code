/*************************************************************************
	> File Name: ol41.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年06月06日 星期三 18时56分42秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define R_M_TEST_ROUND 30

int32_t R_M_TEST(int32_t *num, int32_t n) {
    int64_t x = 0, a, m, ans;
    while (n--) {
        x = x * 10 + num[n];
    }
    for (int32_t i = 0; i < R_M_TEST_ROUND; i++) {
        a = (rand() % (x - 1)) + 1;
        ans = 1;
        m = x - 1;
        while (m) {
            if (m % 2) ans = ans * a % x;
            a = a * a % x;
            m /= 2;
        }
        if (ans != 1) return 0;
    }
    return x;
}

int main() {
    srand(time(0));
    int32_t num[9] = {0}, ans = 0, temp_ans;
    for (int32_t i = 3; i <= 9; ++i) {
        for (int32_t j = 0; j < i; ++j) {
            num[j] = j + 1;
        }
        do {
            temp_ans = R_M_TEST(num, i);
            if (temp_ans > ans) ans = temp_ans;
        } while(next_permutation(num, num + i));
    }
    cout << ans << endl;
    return 0;
}
