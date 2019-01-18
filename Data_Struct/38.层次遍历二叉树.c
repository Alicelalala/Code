/*************************************************************************
	> File Name: 38.层次遍历二叉树.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月14日 星期一 19时40分13秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 100000

typedef struct Node {
    char c;
    struct Node *lchild, *rchild;
} Node, *pNode;

typedef struct Stack {
    pNode *data;
    int top_ind, length;
} Stack;

typedef struct Queue {
    pNode *data;
    int head, tail, size;
} Queue;

Node *getNewNode(char c) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->c = c;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

Stack *init_stack(int len) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (pNode *)malloc(sizeof(pNode) * len);
    s->top_ind = -1;
    s->length = len;
    return s;
}

Node *pop_stack(Stack *s) {
    return s->data[s->top_ind--];
}

void push_stack(Stack *s, pNode node) {
    if (s->top_ind == s->length - 1) return ;
    s->top_ind++;
    s->data[s->top_ind] = node;
    return ;
}

pNode top_stack(Stack *s) {
    return s->data[s->top_ind];
}

int empty(Stack *s) {
    if (s->top_ind < 0) return 1;
    return 0;
}

Queue *init_queue(int len) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (pNode *)malloc(sizeof(pNode) * len);
    q->head = 0;
    q->tail = -1;
    q->size = len;
    return q;
}

Node *pop_queue(Queue *q) {
    return q->data[q->head++];
}

void push_queue(Queue *q, pNode node) {
    if (q->tail == q->size - 1) return ;
    q->tail++;
    q->data[q->tail] = node;
    return ;
}

pNode top_queue(Queue *q) {
    return q->data[q->head];
}

int empty_queue(Queue *q) {
    if (q->tail < q->head) return 1;
    return 0;
}

Node *builtTree(char *str) {
    Node *p = NULL;
    Node *q = NULL;
    Stack *s = init_stack(strlen(str));
    int k = 0;
    int i = 0;
    while(str[i]) {
        switch (str[i]) {
            case '(': {
                k = 0;
                push_stack(s, p);
                p = NULL;
            } break;
            case ')': {
                p = NULL;
                q = pop_stack(s);
            } break;
            case ',': {
                k = 1;
            } break;
            default: {
                p = getNewNode(str[i]);
                if (!empty(s) && k == 0) {
                    top_stack(s)->lchild = p;
                } else if (!empty(s) && k == 1) {
                    top_stack(s)->rchild = p;
                }
                
            } break;
        }
        i++;
    }
    if (p && q == NULL) return p;
    return q;
}

void printTree(Node *root, int len) {
    Queue *q = init_queue(len);
    push_queue(q, root);
    while (!empty_queue(q)) {
        Node *node = top_queue(q);
        if (node != root) {
            printf(" ");
        }
        if (node->lchild) push_queue(q, node->lchild);
        if (node->rchild) push_queue(q, node->rchild);
        printf("%c", pop_queue(q)->c);
    }
    printf("\n");
    return ;
}

int main() {
    char s[MAX_N];
    scanf("%s", s);
    Node *root = builtTree(s);
    printTree(root, strlen(s));
    return 0;
}
