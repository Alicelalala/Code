/*************************************************************************
	> File Name: 15.tree_gyb.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月27日 星期六 11时05分04秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node, *pNode;

typedef struct Stack {
    pNode *data;
    int top_idx, size;
} Stack;

typedef struct Queue {
    pNode *data;
    int head, tail, size;
} Queue;

Queue *init_queue (int len) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (pNode *)malloc(sizeof(pNode));
    q->head = 0;
    q->tail = -1;
    q->size = len;
    return q;
}

int empty_queue (Queue *q) {
    if (q->tail < q->head) return 1;
    return 0;
}

void push_queue (Queue *q, pNode node) {
    if (q->tail + 1 >= q->size) return ;
    q->tail++;
    q->data[q->tail] = node;
}

void pop_queue (Queue *q) {
    if (empty_queue(q)) return ;
    q->head++;
}

pNode top_queue (Queue *q) {
    if (empty_queue(q)) return 0;
    return q->data[q->head];
}

void clear_queue (Queue *q) {
    if (empty_queue(q)) return ;
    free(q->data);
    free(q);
}

Stack *init_stack (int len) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (pNode *)malloc(sizeof(pNode) * len);
    s->top_idx = -1;
    s->size = len;
    return s;
}

int empty (Stack *s) {
    if (s->top_idx < 0) return 1;
    return 0;
}

void push_stack (Stack *s, Node *node) {
    if (s->top_idx + 1 >= s->size) return ;
    s->top_idx++;
    s->data[s->top_idx] = node;
}

void pop_stack (Stack *s) {
    if (empty(s)) return ;
    s->top_idx--;
}

pNode top_stack (Stack *s) {
    if (empty(s)) return 0;
    return s->data[s->top_idx];
}

void clear_stack (Stack *s) {
    if (empty(s)) return ;
    free(s->data);
    free(s);
}

pNode init_node (char a) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = a;
    node->left = NULL;
    node->right = NULL;
    return node;
}

pNode builtTree (char *str, int *num) {
    pNode p = NULL, q = NULL;
    Stack *s = init_stack(strlen(str));
    *num = 0;
    int k = 0;
    while (str[0]) {
        switch (str[0]) {
            case '(': {
                k = 0;
                push_stack(s, p);
                p = NULL;
            } break;
            case ')': {
                q = top_stack(s);
                pop_stack(s);
            } break;
            case ',': {
                k = 1;
                p = NULL;
            } break;
            case ' ': break;
            default : {
                p = init_node(str[0]);
                (*num)++;
                if (!empty(s) && k == 0) {
                    top_stack(s)->left = p;
                } else if (!empty(s) && k == 1) {
                    top_stack(s)->right = p;
                }
            } break;
        }
        str++;
    }
    if (p && !q) q = p;
    clear_stack(s);
    return q;
}

void outputLevel (Node *root, int num) {
    if (num == 0) return ;
    printf("%c", root->data);
    pNode temp = root;
    Queue *q = init_queue(num);
    push_queue(q, temp);
    while (!empty_queue(q)) {
        temp = top_queue(q);
        if (temp->left) {
            printf(" %c", temp->left->data);
            push_queue(q, temp->left);
        }
        if (temp->right) {
            printf(" %c", temp->right->data);
            push_queue(q, temp->right);
        }
        pop_queue(q);
    }
    printf("\n");
    clear_queue(q);
}

void output (pNode root) {
    if (root == NULL) return ;
    printf("%c ", root->data);
    output(root->left);
    output(root->right);
}

void clear_tree (Node *root) {
    if (root == NULL) return ;
    clear_tree(root->left);
    clear_tree(root->right);
    free(root);
}


int main() {
    char buffer[50];
    scanf("%s", buffer);
    int num;
    pNode root = builtTree(buffer, &num);
    printf("%d\n", num);
    output(root);
    printf("\n");
    outputLevel(root, num);
    clear_tree(root);
    return 0;
}
