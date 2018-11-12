/*************************************************************************
	> File Name: 232.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月26日 星期五 10时48分54秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int top_idx, size;
} MyQueue;

MyQueue *s = NULL;

void init();
__attribute__((constructor))
void init () {
    s = (MyQueue *)malloc(sizeof(MyQueue));
    s->data = (int *)malloc(sizeof(int) * 10);
    s->top_idx = -2;
    s->size = 10;
}

/** Initialize your data structure here. */
MyQueue *myQueueCreate(int maxSize) {
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->data = (int *)malloc(sizeof(int) * maxSize);
    q->top_idx = -1;
    q->size = maxSize;
    return q;
}

int empty (MyQueue *s) {
    if (s->top_idx < 0) return 1;
    return 0;
}

int pop (MyQueue *s) {
    if (s->top_idx < 0) return 0;
    return s->data[s->top_idx--];
}

int top (MyQueue *s) {
    if (empty(s)) return 0;
    return s->data[s->top_idx];
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    if (s->top_idx == -2) {
        s = myQueueCreate(obj->size);
    }
    if (obj->top_idx + 1 >= obj->size) return ;
    obj->top_idx++;
    obj->data[obj->top_idx] = x;
    //printf("%d\n", x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if (s->top_idx < 0) {
        if (obj->top_idx < 0) return 0;
        while (!empty(obj)) {
            myQueuePush(s, top(obj));
            pop(obj);
        }
    }
    int temp = pop(s);
    return temp;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (s->top_idx < 0) {
        if (obj->top_idx < 0) return 0;
        while (!empty(obj)) {
            myQueuePush(s, top(obj));
            pop(obj);
        }
    }
    return top(s);
}

/** Returns whether the queue is empty. */
int myQueueEmpty(MyQueue* obj) {
    if (s->top_idx < 0 && obj->top_idx < 0) return 1;
    return 0;
}

void myQueueFree(MyQueue* obj) {
    if (s->top_idx < 0) {
        if (obj->top_idx < 0) return ;
        free(obj->data);
        free(obj);
        return ;
    }
    free(obj->data);
    free(obj);
}

int main() {
    MyQueue *q = myQueueCreate(30);
    //for (int i = 1; i <= 5; i++) {
    //    myQueuePush(q, i);
    //}
    //printf("%d\n", myQueuePeek(q));
    //printf("%d\n", myQueuePop(q));
    //printf("%d\n", myQueuePeek(q));
    //printf("%d\n", myQueuePop(q));
    printf("%d\n", myQueueEmpty(q));
    return 0;
}
