/*************************************************************************
	> File Name: binary_search.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月23日 星期日 10时41分06秒
 ************************************************************************/

#include <stdio.h>

int binary_search (int *data, int x, int n) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (data[mid] == x) return mid;
        if (data[mid] > x) tail = mid - 1;
        else head = mid + 1;
    }
    return -1;
}


int main() {
    int ary[6];
    for (int i = 0; i < 6; i++) {
        ary[i] = i;
    }
    printf("%d\n", binary_search(ary, 4, 6));
    return 0;
}
