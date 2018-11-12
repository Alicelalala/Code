/*************************************************************************
	> File Name: 18.蒜头君捡石子.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年11月02日 星期五 12时16分54秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b; b = __temp; \
}

typedef struct Node {
    int p, s;
} Node;

typedef struct Heap {
    Node *data;
    int size;
} Heap;

Heap *init (int len) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->data = (Node *)malloc(sizeof(Node) * len);
    h->size = 0;
    return h;
}

int comp (Node n1, Node n2) {
    if (n1.p < n2.p) return 1;
    if (n1.p == n2.p && n1.s < n2.s) return 1;
    return 0;
}

void push (Heap *h, Node value) {
    h->data[h->size] = value;
    int ind = h->size;
    int f = (ind - 1) / 2;
    while (comp(h->data[ind], h->data[f])) {
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
    if (l < n && comp(h->data[l], h->data[ind])) {
        ind = l;
    }
    if (r < n && comp(h->data[r], h->data[ind])) {
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

Node top (Heap *h) {
    return h->data[0];
}

int empty (Heap *h) {
    return h->size == 0;
}

void output (Heap *h) {
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->data[i].p);
    }
    printf("\n");
}

void clear (Heap *h) {
    free(h->data);
    free(h);
}

int main() {
    int t, n, p, s;
    scanf("%d", &t);
    Node node;
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        int flag = 0;
        Heap *h = init(n + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d%d", &p, &s);
            node.p = p;
            node.s = s;
            push(h, node);
        }
        output(h);
        Node temp;
        while (!empty(h)) {
            flag++;
            printf("+++%d\n", top(h).p);
            printf("+++--%d\n", h->data[1].p);
            if (flag & 1) {
                temp = top(h);
                temp.p += temp.s;
                printf("+++====%d\n", top(h).p);
                pop(h);
                push(h, temp);
            } else {
                pop(h);
            }
            output(h);
        }
        printf("%d\n", temp.p);
        clear(h);
    }
    return 0;
}
