/*************************************************************************
	> File Name: 201912-4.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月14日 星期一 18时13分49秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 50000

typedef struct Data {
    int v, u, t;
} Data;

typedef struct Node {
    Data data;
    struct Node *next;
} Node;

Node *insert(Node *head, Node *node) {
    if (head == NULL) {
        head = node;
        return head;
    }
    Node *p = head;
    if (p->data.t > node->data.t) {
        node->next = head;
        head = node;
        return head;
    }
    Node *q = head->next;
    while (q && q->data.t < node->data.t) {
        p = p->next;
        q = q->next;
    }
    node->next = q;
    p->next = node;
    return head;
}

void kluskal(Node *head) {
    Node *node = head;
    int A[MAX_N + 5] = {0};
    int B[MAX_N + 5] = {0};
    while (node) {
        int v, u, t;
        v = node->data.v;
        u = node->data.u;
        t = nofr->data.t;
        if ((A[u] && A[v]) || (B[u] && B[v])) {
            node = node->next;
            continue;
        }
        if ((A[u] == 0 && A[v] == 0) || (B[u] == 0 && B[v] == 0)) {
            A[u] = 1;
            A[v] = 1;
            continue;
        }
    }
}

void output(Node *head) {
    Node *node = head;
    while (node) {
        printf("%d %d %d\n", node->data.v, node->data.u, node->data.t);
        node = node->next;
    }
    return ;
}

int main() {
    int n, m, root;
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &root);
    Node *head = NULL;
    int v, u, t;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &v, &u, &t);
        Node *node = (Node *)malloc(sizeof(Node));
        node->data.v = v;
        node->data.u = u;
        node->data.t = t;
        node->next = NULL;
        head = insert(head, node);
    }
    printf("-------\n");
    output(head);
    int A[MAX_N + 5] = {0};
    int B[MAX_N + 5] = {0};
    kluskal(head);
    return 0;
}
