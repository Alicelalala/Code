/*************************************************************************
	> File Name: ol_tes.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月13日 星期日 14时27分46秒
 ************************************************************************/

#include <stdio.h>

int binary_search(int *arr, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) {
            tail = mid - 1;
        } else {
            head = mid + 1;
        }
    }
    return -1;
}

int main() {
    int a[] = {1, 3, 3, 5, 6, 8, 9, 20};
    printf("%d", binary_search(a, 8, 8));
    return 0;
}
