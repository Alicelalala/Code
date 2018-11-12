/*************************************************************************
	> File Name: 2.优化建堆.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年11月03日 星期六 14时15分11秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) { \
    __typeof(a) __temp = a; a = b; b = __temp; \
}

void update (int *p, int ind, int n) {
    int temp = ind;
    if ((ind << 1) <= n && p[temp] < p[ind << 1]) temp = ind << 1;
    if ((ind << 1 | 1) <= n && p[temp] < p[ind << 1 | 1]) temp = ind << 1 | 1;
    if (temp != ind) {
        swap(p[temp], p[ind]);
        update(p, temp, n);
    }
}

//自下而上建堆，时间复杂度O(n)
//堆排序，时间复杂度O(nlog(n))——O(nlog(n))和O(logn!)是同阶函数
void heap_sort (int *arr, int n) {
    int *p = arr - 1; //让p[1] = arr[0]
    for (int i = n >> 1; i >= 1; i--) {
        update(p, i, n);
    }
    for (int i = n; i > 1; i--) {
        swap(p[i], p[1]);
        update(p, 1, i - 1);
    }
    return ;
}

void output (int *num, int n) {
    printf("Arr = [");
    for (int i = 0; i < n; i++) {
        printf(" %d", num[i]);
        i == n - 1 || printf(","); //||否则
    }
    printf("]\n");
}

int main() {
    srand(time(0));
    #define MAX_N 20 
    int arr[MAX_N];
    for (int i = 0; i < MAX_N; i++) arr[i] = rand() % 100;
    output(arr, MAX_N);
    heap_sort(arr, MAX_N);
    output(arr, MAX_N);
    return 0;
}
