/*************************************************************************
	> File Name: 1.堆.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年11月03日 星期六 10时46分06秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) { \
    __typeof(a) __temp = a; a = b; b = __temp; \
}

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
    while (h->data[ind] > h->data[f]) {
        swap(h->data[ind], h->data[f]);
        ind = f;
        f = (ind - 1) / 2;
    }
    h->size++;
}

void update (Heap *h, int pos, int n) {
    int ind = pos;
    int l = pos * 2 + 1;
    int r = pos * 2 + 2;
    if (l < n && h->data[l] > h->data[ind]) {
        ind = l;
    }
    if (r < n && h->data[r] > h->data[ind]) {
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

void Heap_sort (Heap *h) {
    for (int i = h->size - 1; i >= 1; i--) {
        swap(h->data[i], h->data[0]);
        update(h, 0, i);
    }
}

int top (Heap *h) {
    return h->data[0];
}

void output (Heap *h) {
    int n = 0;
    for (int i = 0; i < h->size; i++) {
        if (i == 2 * n + 1) {
            printf("\n");
            n = 2 * n + 1;
        } else { 
            printf("%d ", h->data[i]);
        }
    }
    printf("\n");
}

void clear (Heap *h) {
    free(h->data);
    free(h);
}

int main() { 
    srand(time(0));
    Heap *h = init(10);
    for (int i = 0; i < 10; i++) {
        int value = rand() % 100 + 1;
        push(h, value);
    }
    output(h);
    Heap_sort(h);
    output(h);
    return 0;
}
