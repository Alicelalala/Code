/*************************************************************************
	> File Name: 20.最小的10个数.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年11月03日 星期六 15时55分59秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 100000000

#define swap(a, b) { \
    __typeof(a) __temp = a; a = b; b = __temp; \
}

//一亿个数中， 找到最小的十个数
//建一个十个元素的大顶堆
//如果新来的元素小于堆顶元素，堆顶元素出堆，新元素入堆

typedef struct Heap {
    int *data;
    int size;
} Heap;

Heap *init (int max) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->data = (int *)malloc(sizeof(int) * max);
    h->size = 0;
    return h;
}

void update (Heap *h, int pos, int n) {
    int ind = pos;
    int l = pos * 2 + 1;
    int r = pos * 2 + 2;
    if (l < n && h->data[l] > h->data[ind]) {
        ind = l;
    }
    if (l < n && h->data[r] > h->data[ind]) {
        ind = r;
    }
    if (ind != pos) {
        swap(h->data[ind], h->data[pos]);
        update(h, ind, n);
    }
}

void push (Heap *h, int value) {
    h->data[h->size] = value;
    int ind = h->size;
    int f = (ind - 1) / 2;
    while (h->data[ind] > h->data[f]) {
        swap(h->data[ind], h->data[f]);
        ind = f;
        f = (ind - 1) / 2;
    }
    h->size++;
}

void pop (Heap *h) {
    swap(h->data[0], h->data[h->size - 1]);
    h->size--;
    update(h, 0, h->size);
}

int top (Heap *h) {
    return h->data[0];
}

void output (Heap *h) {
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->data[i]);
    }
    printf("\n");
}

void clear (Heap *h) {
    free(h->data);
    free(h);
}

int main() {
    srand(time(0));
    Heap *h = init(15);
    for (int i = 0; i < MAX_N; i++) {
        int a = rand() % MAX_N;
        if (i >= 10) {
            if (a < top(h)) {
                pop(h);
                push(h, a);
            }
        } else {
            push(h, a);
        }
    }
    output(h);
    return 0;
}
