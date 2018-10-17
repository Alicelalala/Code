/*************************************************************************
	> File Name: 4.cirQueue.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月13日 星期六 14时54分20秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct Queue {
    int *data;
    int head, tail, length, count;
} Queue;

void init (Queue *q, int length) {
    q->data = (int *)malloc(sizeof(int) * length);
    q->head = 0;
    q->tail = -1;
    q->length = length;
    q->count = 0;
}

int push (Queue *q, int value) {
    if (q->count >= q->length) return 0;
    q->tail = (q->tail + 1) % (q->length);
    q->data[q->tail] = value;
    q->count++;
    return 1;
}

void output (Queue *q) {
    int i = q->head;
    do {
        if (i != q->head) {
            printf(" ");
        }
        printf("%d", q->data[i]);
        i = (i + 1) % (q->length);
    } while (i != (q->tail) % (q->length));
    printf("\n");
}

int front (Queue *q) {
    return q->data[q->head];
}

int empty (Queue *q) {
    return q->count == 0;
}

void pop (Queue *q) {
    q->head = (q->head + 1) % (q->length);
    q->count--;
}

void clear (Queue *q) {
    free(q->data);
    free(q);
}

int main() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    init(q, 100);
    for (int i = 1; i <= 10; i++) {
        push(q, i);
    }
    output(q);
    if (!empty(q)) {
        printf("%d\n", front(q));
        pop(q);
    }
    output(q);
    return 0;
}
