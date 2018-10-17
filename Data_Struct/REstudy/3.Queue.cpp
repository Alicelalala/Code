/*************************************************************************
	> File Name: 3.Queue.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月13日 星期六 14时13分23秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct Queue {
    int *data;
    int head, tail, length;
} Queue;

void init (Queue *q, int length) {
    q->data = (int *)malloc(sizeof(int) * length);
    q->head = 0;
    q->tail = -1;
    q->length = length;
}

int push (Queue *q, int value) {
    if (q->tail + 1 >= q->length) return 0;
    q->tail++;
    q->data[q->tail] = value;
    return 1;
}

int isempty (Queue *q) {
    if (q->head > q->tail) return 1;
    return 0;
}

void pop (Queue *q) {
    q->head++;
}

int front (Queue *q) {
    return q->data[q->head];
}

int output (Queue *q) {
    for (int i = q->head; i <= q->tail; i++) {
        if (i != q->head) {
            printf(" ");
        }
        printf("%d", q->data[i]);
    }
}

void clear (Queue *q) {
    free(q->data);
    free(q);
}

int main() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    init(q, 105);
    int m, value, n;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        push(q, value);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        if (!isempty(q)) {
            pop(q);
        }
    }
    if (!isempty(q)) {
        printf("%d\n", front(q));
    }
    output(q);
    clear(q);
    return 0;
}

