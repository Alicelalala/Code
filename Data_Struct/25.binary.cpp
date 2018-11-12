/*************************************************************************
	> File Name: 25.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年11月06日 星期二 19时27分25秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define P(func) { \
    printf("%s = %d\n",  #func, func); \
}

int binary_search (int *num, int n, int x) {
    int head = 0, tail = n  -1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] > x) tail = mid - 1;
        else head = mid + 1;
    }
    return -1;
}

//111111111000000000
int binary_search2 (int *num, int n) {
    int head = -1, tail = n - 1, mid;
        while (head < tail) {
            mid = (head + tail + 1) >> 1;
            if (num[mid] == 1) head = mid;
            else tail = mid - 1;
        }
    return head;
}

//00000011111111
int binary_search3 (int *num, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == 1) tail = mid;
        else head = mid + 1;
    }
    return head;
}

int main() {
    int arr1[] = {1, 4, 5, 7, 9, 10, 13};
    int arr2[] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    int arr3[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    P(binary_search(arr1, 7, 9));
    P(binary_search2(arr2, 10));
    P(binary_search3(arr3, 11));
    return 0;
}
