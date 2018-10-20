/*************************************************************************
	> File Name: 3.Stack.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月17日 星期三 19时21分34秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Stack {
    int *element;
    int max_len, top_ind;
} Stack;

void init (Stack *s, int length) {
    s->element = (int *)malloc(sizeof(int) * length);
    s->max_len = length;
    s->top_ind = -1;
}

void push (Stack *s, int element) {
    if (s->top_ind >= s->max_len - 1) return ;
    s->top_ind++;
    s->element[s->top_ind] = element;
}

int empty (Stack *s) {
    if (s->top_ind < 0) return 1;
    return 0;
}

void pop (Stack *s) {
    if (empty(s)) return ;
    s->top_ind--;
}

int precedeBit (char a) {
    switch (a) {
        case '+' : return 0;
        case '-' : return 0;
        case '*' : return 1;
        case '/' : return 1;
    }
}

int precede(char a, char b) {
    if (precedeBit(a) >= precedeBit(b)) return 1;
    return 0;
}

int operate (char c, int a, int b) {
    switch (c) {
        case '+' : return a + b;
        case '-' : return a - b;
        case '*' : return a * b;
        case '/' : return a / b;
    }
}

int top (Stack *s) {
    return s->element[s->top_ind];
}

void clear (Stack *s) {
    free(s->element);
    free(s);
}

int main() {
    int temp;
    char buffer[100];
    Stack *number = (Stack *)malloc(sizeof(Stack));
    Stack *operators = (Stack *)malloc(sizeof(Stack));
    init(number, 100);
    init(operators, 100);
    int n;
    scanf("%d", &n);
    scanf("%s", buffer);
    for (int i = 0; i < n; i++) {
        temp = 0;
        while (isdigit(buffer[i]) && i < n) {
            temp = temp * 10 + (buffer[i] - '0');
            i++;
        }
        push(number, temp);
        if (i == n) break;
        if (!empty(operators) && precede(top(operators), buffer[i])) {
            int a = top(number);
            pop(number);
            int b = top(number);
            pop(number);
            char c = top(operators);
            pop(operators);
            push(number, operate(c, b, a));
            push(operators, buffer[i]);
        } else {
            push(operators, buffer[i]);
        }
    }
    while (!empty(operators)) {
        int a = top(number);
        pop(number);
        int b = top(number);
        pop(number);
        char c = top(operators);
        pop(operators);
        push(number, operate(c, b, a));
    }
    printf("%d\n", top(number));
    clear(number);
    clear(operators);
    return 0;
}

