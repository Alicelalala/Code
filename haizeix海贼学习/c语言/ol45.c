/*************************************************************************
	> File Name: ol45.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月29日 星期日 14时38分23秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int64_t Pentagonal(int64_t n) {
    return n * (3 * n - 1) / 2;
}
int64_t power2(int64_t n) {
    return n * n;
}
int binary_search(int64_t n, int64_t (*func)(int64_t)) {
    int64_t head = 1, tail = n, mid;
    while (head <= tail) {
        mid = (head + tail) / 2;
        int64_t value = func(mid);
        if (value == n)return 1;
        if (value > n) tail = mid - 1;
        else head = mid + 1;
    }
    return 0;
}



int main() {
    int64_t n = 144;
    while (!binary_search(n * (2 * n - 1), Pentagonal)) ++n;
    printf("%"PRId64"\n", n * (2 * n - 1));
    printf("%d : %d\n", 5, binary_search(5, power2));
    printf("%d : %d\n", 9, binary_search(9, power2));
    return 0;
}
