
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int top_idx, size;
} MyQueue;

MyQueue *s = NULL;

int myQueueEmpty(MyQueue *);
int myQueuePeek(MyQueue *);

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->data = (int *)malloc(sizeof(int) * maxSize);
    q->top_idx = -1;
    q->size = maxSize;
    if (s == NULL) {
        s = myQueueCreate(maxSize);
    }
    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    if (obj->top_idx + 1 >= obj->size) return ;
    obj->top_idx++;
    obj->data[obj->top_idx] = x;
}

void stackPop (MyQueue *q) {
    q->top_idx--;
}

int stackPeek (my)

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if (s->top_idx < 0) {
        if (myQueueEmpty(obj)) return 0;
        while (!myQueueEmpty(obj)) {
            myQueuePush(s, stackPeek(obj));
            stackPop(obj);
        }
    }
    stackPop(s);
    return 1;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
}

/** Returns whether the queue is empty. */
int  myQueueEmpty(MyQueue* obj) {
    
    if (obj->top_idx < 0) return 1;
    return 0;
}

void myQueueFree(MyQueue* obj) {
    if (obj == NULL) return ;
    free(obj->data);
    free(obj);
}

int main() {
    MyQueue *q = myQueueCreate(30);
    for (int i = 1; i <= 5; i++) {
        myQueuePush(q, i);
    }
    printf("%d\n", myQueuePeek(q));
    return 0;
}
