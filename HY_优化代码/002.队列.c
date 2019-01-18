/*************************************************************************
	> File Name: 002.队列.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月15日 星期二 15时48分04秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *data;
    int head, tail, size;
} Queue;

Queue *init_queue(int len) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * len);
    q->head = 0;
    q->tail = -1;
    q->size = len;
    return q;
}

void push_queue(Queue *q, int value) {
    if (q->tail == q->size - 1) return ;
    q->tail++;
    q->data[q->tail] = value;
    return ;
}

int pop_queue(Queue *q) {
    return q->data[q->head++];
}

int front_queue(Queue *q) {
    return q->data[q->head];
}

int empty_queue(Queue *q) {
    return q->tail < q->head;
}

void clear_queue(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

void output_queue(Queue *q) {
    printf("Queue = [");
    for (int i = q->head; i <= q->tail; i++) {
        printf("%d", q->data[i]);
        i != q->tail && printf(",");
    }
    printf("]\n");
    return ;
}

int main() {
    Queue *q = init_queue(10);
    for(int i = 0; i < 10; i++) {
        push_queue(q, i + 1);
    }
    pop_queue(q);
    output_queue(q);
    return 0;
}
