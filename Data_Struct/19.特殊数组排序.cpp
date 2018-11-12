/*************************************************************************
	> File Name: 19.特殊数组排序.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年11月03日 星期六 15时10分31秒
 ************************************************************************/

//一个无序数组排序，排完序后数组脚标不会超过它原来脚标的十位
//如：a[11]排序后a[1]~a[21]中一个数
//时间复杂度O(10 * n * log(n))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(a, b) { \
    __typeof(a) __temp = a; a = b; b = __temp; \
}

int arr[] = {9, 8, 7, 3, 2, 1, 4, 5, 6, 11, 13, 19, 10, 20, 21, 18, 12, 14, 15, 17, 18, 22, 25, 30, 26, 28};

typedef struct Heap {
    int *data;
    int size;
} Heap;

Heap *init (int max_len) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->data = (int *)malloc(sizeof(int) * max_len);
    h->size = 0;
    return h;
}

void push (Heap *h, int value) {
    h->data[h->size] = value;
    int ind = h->size;
    int f = (ind - 1) / 2;
    while (h->data[ind] < h->data[f]) {
        swap(h->data[ind], h->data[f]);
        ind = f;
        f = (ind - 1) / 2;
    }
    h->size++;
}

int top (Heap *h) {
    return h->data[0];
}

void update (Heap *h, int pos, int n) {
    int ind = pos;
    int l = pos * 2 + 1;
    int r = pos * 2 + 2;
    if (l < n && h->data[l] < h->data[ind]) {
        ind = l;
    }
    if (r < n && h->data[r] < h->data[ind]) {
        ind = r;        
    }
    if (ind != pos) {
        swap(h->data[ind], h->data[pos]);
        update(h, ind, n);
    }
}

void pop (Heap *h) {
    swap(h->data[0], h->data[h->size - 1]);
    h->size--;
    update(h, 0, h->size);
}

void output () {
    printf("Arr: [");
    for (int i = 0; arr[i]; i++) {
        i == 0 || printf(" ");
        printf("%d", arr[i]);
    }
    printf("]\n");
}

int main() {
    Heap *h = init(30);
    for (int i = 0; i < 10; i++) {
        push(h, arr[i]);
    }
    output();
    int n = 0;
    for (int i = 10; arr[i]; i++) {
        arr[n++] = top(h);
        pop(h);
        push(h, arr[i]);
    }
    while (h->size > 0) {
        arr[n++] = top(h);
        pop(h);
    }
    output();
    return 0;
}
