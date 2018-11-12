/*************************************************************************
	> File Name: 9.calc_delete.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月22日 星期一 21时21分43秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
#define INF 0x3f3f3f3f

typedef struct Node {
    char element;
    struct Node *lchild, *rchild;
} Node, *PNode;

typedef struct Stack {
    PNode *data;
    int top_idx, size;
} Stack;

Stack *init (int len) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (PNode *)malloc(sizeof(PNode) * len);
    s->top_idx = -1;
    s->size = len;
    return s;
}

Node *init_node (char a) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->element = a;
    n->lchild = NULL;
    n->rchild = NULL;
    return n;
}

void push (Stack *s, Node *a) {
    if (s->top_idx + 1 >= s->size) return ;
    s->top_idx++;
    s->data[s->top_idx] = a;
}

void pop (Stack *s) {
    if (s->top_idx < 0) return ;
    s->top_idx--;
}

PNode top (Stack *s) {
    if (s->top_idx < 0) return 0;
    return s->data[s->top_idx];
}

int empty (Stack *s) {
    return s->top_idx == -1;
}

PNode built (char buf[]) {
    int len = strlen(buf);
    Stack *s = init(35);
    PNode node1 = NULL;
    PNode a = NULL;
    PNode b = NULL;
    for (int i = 0; i < len; i++) {
        switch (buf[i]) {
            case ')': {
                if (top(s)->element == ',') {
                    a = NULL;
                    pop(s);
                    b = top(s);
                    pop(s);
                    pop(s);
                    node1 = top(s);
                    node1->rchild = a;
                    node1->lchild = b;
                } else {
                    a = top(s);
                    pop(s);
                    pop(s);
                    if (top(s)->element == '(') {
                        b = NULL;
                    } else {
                        b = top(s);
                        pop(s);
                    }
                    pop(s);
                    node1 = top(s);
                    node1->rchild = a;
                    node1->lchild = b;
                }
            } break;
            default :
            a = init_node(buf[i]);
            push(s, a);
            break;
        }
    }
    return node1;
}

void output (Node *node) {
    if (node == NULL) return ;
    printf("%c", node->element);
    if (node->lchild || node->rchild) {
        printf("(");
    }
    if (node->lchild != NULL) output(node->lchild);
    if (node->lchild || node->rchild) {
        printf(",");
    }
    if (node->rchild != NULL) output(node->rchild);
    if (node->lchild || node->rchild) {
        printf(")");
    }
}

void clear(Node *);
                        
void delete_node (Node *node, char a) {
    if (node == NULL) return ;
    if (node->lchild != NULL) {
        if (node->lchild->element == a) {
            node->lchild = NULL;
            return ;
        }
        delete_node(node->lchild, a);
    }
    if (node->rchild != NULL) {
        if (node->rchild->element == a) {
            node->rchild = NULL;
            return ;
        }
        delete_node(node->rchild, a);
    }
}

void clear (Node *node) {
    if (node == NULL) return ;
    if (node->lchild) clear(node->lchild);
    if (node->rchild) clear(node->rchild);
    free(node);
}

int main() {
    char buffer[35], ch;
    int i = 0;
    while (scanf("%c", &ch)) {
        if (ch == '\n') {
            break;
        }
        buffer[i++] = ch;
    }
    ch = getchar();
    //printf("%c\n", ch);
    //int len = strlen(buffer);
    //output(node);
    if (buffer[0] == ch) {
        printf("\n");
        return 0;
    } else {
        PNode node = built(buffer);
        delete_node(node , ch);
        output(node);
        printf("\n");
    }
    return 0;
}
