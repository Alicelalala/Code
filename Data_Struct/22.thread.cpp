/*************************************************************************
	> File Name: 22.thread.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年11月04日 星期日 14时49分22秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define NORMAL 0
#define THREAD 1

typedef struct Node {
    int key, ltag, rtag;
    struct Node *lchild, *rchild;
} Node;

Node *init (int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    p->ltag = p->rtag = NORMAL;
    return p;
}

Node *insert (Node *root, int key) {
    if (root == NULL) return init(key);
    if (root->key == key) return root;
    if (key < root->key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;
}

void build (Node *root) {
    if (root == NULL) return ;
    static Node *pre = NULL;
    if (root->lchild == NULL) {
        root->lchild = pre;
        root->ltag = THREAD;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;
    if (root->ltag == NORMAL) {
        build(root->lchild);
    }
    if (root->rtag == NORMAL) {
        build(root->rchild);
    }
    return ;
}

void output (Node *root) {
    int status = 1;
    Node *p = root;
    while (p) {
        switch (status) {
            case 1: {
                printf("%d ", root->key);
                status = 2;
            } break;
            case 2: {
                if (p->ltag == NORMAL && p->lchild) {
                    p = p->lchild;
                    status = 1;
                } else {
                    p = p->rchild;
                    status = 1;
                } 
            } break;
        }
    }
}

void outputRoot (Node *root) {
    if (root == NULL) return ;
    printf("%d ", root->key);
    output(root->lchild);
    output(root->rchild);
}

int clear (Node *root) {
    if (root == NULL) return 0;
    root->ltag == NORMAL && clear(root->lchild);
    root->rtag == NORMAL && clear(root->rchild);
    free(root);
    return 0;
}

int main () {
    int n;
    Node *root = NULL;
    while (scanf("%d", &n) != EOF) {
        root = insert(root, n);
    }
    outputRoot(root);
    printf("\n");
/*    build(root);
    outputRoot(root);
    printf("\n");
    output(root);
    printf("\n"); */
    clear(root);
    return 0;
}
