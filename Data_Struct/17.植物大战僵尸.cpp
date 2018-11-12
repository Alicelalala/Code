/*************************************************************************
	> File Name: 17.植物大战僵尸.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年11月01日 星期四 19时28分48秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>


#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b; b = __temp; \
}

typedef struct Node {
    int id, f;
} Node;

typedef struct Heap {
    Node *data;
    int size;
} Heap;

Heap *init (int max) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->data = (Node *)malloc(sizeof(Node) * max);
    h->size = 0;
    return h;
}

int comp (Node a, Node b) {
    if (a.f > b.f) return 1;
    if (a.f == b.f && a.id < b.id) return 1;
    return 0;
}

void push (Heap *h, Node node) {
    h->data[h->size] = node; 
    int ind = h->size;
    int father = (ind - 1) / 2;
    while (comp(h->data[ind], h->data[father])) {
        swap(h->data[ind], h->data[father]);
        ind = father;
        father = (ind - 1) / 2;
    }
    h->size++;
}

void update (Heap *h, int pos, int n) {
    int l = pos * 2 + 1;
    int r = pos * 2 + 2;
    int ind = pos;
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

void output (Heap **h) {
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j < h[i]->size; j++) {
            printf("%d ", h[i]->data[j].f);
        }
    }
    printf("\n");
}

void clear (Heap *h) {
    free(h->data);
    free(h);
}

int main() {
    int t;
    scanf("%d", &t);
    Heap **h = (Heap **)malloc(sizeof(Heap *) * 101);
    for (int j = 0; j <= 100; j++) {
        h[j] = init(5000);
    }
    for (int i = 0; i < t; i++) {
        int n, f, s;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d%d", &f, &s);
            Node node;
            node.id = j + 1;
            node.f = f;
            push(h[s], node);
        }
        //output(h);
        int num = 0;
        printf("Case #%d:\n", i + 1);
        while (num < n) {
            Node node, node2;
            node.id = 50000;
            node.f = 0;
            int ans = 0;
            for (int j = 1; j <= 100; j++) {
                if (empty(h[j])) continue;
                node2 = top(h[j]);
                node2.f += j * num;
                if (comp(node2, node)) {
                    node = node2;
                    ans = j;
                }
            }
            if (num) {
                printf(" ");
            }
            printf("%d", top(h[ans]).id);
            pop(h[ans]);
            num++;
        }
        printf("\n");
    }
    for (int i = 0; i <= 100; i++) {
        clear(h[i]);
    }
    return 0;
}
