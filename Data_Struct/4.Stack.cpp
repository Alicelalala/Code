#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct Node {
    int dataty; 
    int data;
} Node;

typedef struct Stack {
    Node *element;
    int length, top_len;
} Stack;

void init (Stack *s, int len) {
    s->element = (Node *)malloc(sizeof(Node) * len);
    s->length = len;
    s->top_len = -1;
}

void push (Stack *s, Node ret) {
    if (s->top_len >= s->length - 1) return ;
    s->top_len++;
    s->element[s->top_len] = ret;
    return ;
}

void pop (Stack *s) {
    if (s->top_len < 0) return ;
    s->top_len--;
}

Node top (Stack *s) {
    return s->element[s->top_len];
}

int empty (Stack *s) {
    return s->top_len < 0;
}

int alter (char a) {
    switch (a) {
        case '+' :
        case '-' : return 0;
        case '*' : 
        case '/' : return 1;
    }
}

int precede (char a, char b) {
    if (alter(a) >= alter(b)) return 1;
    return 0;
}

int operate (Node op, Node a, Node b) {
    switch (op.data) {
        case '+' : return a.data + b.data;
        case '-' : return a.data - b.data;
        case '*' : return a.data * b.data;
        case '/' : return a.data / b.data;

    }
}

Node result (Stack *s) {
    Stack *n = (Stack *)malloc(sizeof(Stack));
    init(n, 25);
    Node ret;
    for (int i = 0; i <= s->top_len; i++) {
        if (s->element[i].dataty == 0) {
            push(n, s->element[i]);
        } else {
            Node a = top(n);
            pop(n);
            Node b = top(n);
            pop(n);
            int value = operate(s->element[i], b, a);
            ret.dataty = 0;
            ret.data = value;
            push(n, ret);
        }
    }
    return top(n);
}

int main() {
    Stack *number = (Stack *)malloc(sizeof(Stack));
    Stack *operators = (Stack *)malloc(sizeof(Stack));
    init(number, 25);
    init(operators, 25);
    Node ret;
    Node *array = (Node *)malloc(sizeof(Node) * 25);
    char *buffer = (char *)malloc(sizeof(char) * 25);
 	scanf("%s", buffer);
    while (*buffer) {
        //printf("%p\n", buffer[0]);
        if (isdigit(buffer[0])) {
            ret.dataty = 0;
            ret.data = buffer[0] - '0';
            //putchar(buffer[0]);
            push(number, ret);
        } else {
            while (!empty(operators) && precede(top(operators).data, buffer[0])) {
                push(number, top(operators));
                pop(operators);
            }
            ret.dataty = 1;
            ret.data = buffer[0];
            push(operators, ret);
        }
        buffer++;
    }
    while (!empty(operators)) {
        push(number, top(operators));
        pop(operators);
    }
    printf("%d\n", result(number).data);
    return 0;
}
