/*************************************************************************
	> File Name: 001.栈.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月15日 星期二 15时01分02秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack {
    int *data;
    int top_ind, size;
} Stack;

Stack *init_stack(int len) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * len);
    s->top_ind = -1;
    s->size = len;
    return s;
}

void push_stack(Stack *s, int  value) {
    if (s->top_ind == s->size - 1) return ;
    s->top_ind += 1;
    s->data[s->top_ind] = value;
    return ;
}

int pop_stack(Stack *s) {
    return s->data[s->top_ind--];
}

int top_stack(Stack *s) {
    return s->data[s->top_ind];
}

int empty_stack(Stack *s) {
    if (s->top_ind < 0) return 1;
    return 0;
}

void output_stack(Stack *s) {
    if (s == NULL) return ;
    printf("Stack = [");
    for (int i = s->top_ind; i >= 0; --i) {
        printf("%d", s->data[i]);
        i && printf(",");
    }
    printf("]\n");
    return ;
}

void clear_stack(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}
