/*************************************************************************
	> File Name: 14.tree.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月26日 星期五 13时58分15秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
}Node;

Node* init(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

void preorder(Node *node) {
    printf("%d ", node->data);
	if (node->lchild != NULL) {
     	preorder(node->lchild);
    }
    if (node->rchild != NULL) {
        preorder(node->rchild);
    }
}

void inorder(Node *node) {
    if (node->lchild != NULL) {
        inorder(node->lchild);
    }
    printf("%d ", node->data);
    if (node->rchild != NULL) {
        inorder(node->rchild);
    }
}

void postorder(Node *node) {
    if (node->lchild != NULL) {
        postorder(node->lchild);
    }
    if (node->rchild != NULL) {
        postorder(node->rchild);
    }
    printf("%d ", node->data);
}

Node* build_demo() {
    Node *node = init(4);
    node->lchild = init(2);
    node->lchild->rchild = init(1);
    node->lchild->rchild->rchild = init(3);
    node->rchild = init(6);
    node->rchild->lchild = init(5);
    node->rchild->rchild = init(7);
    return node;
}

int height (Node *root) {
    if (root == NULL) return 0;
    int l = height(root->lchild);
    if (l < 0) return -2;
    int r = height(root->rchild);
    if (abs(l - r) > 1) return -2;
    printf("%d %d\n", l, r);
    return (l > r ? l : r) + 1;
}


int getLeaf (Node *root, int *sum) {
    if (root == NULL) return 0;
    if (root->lchild == NULL && root->rchild == NULL) *sum += 1;
    getLeaf(root->lchild, sum);
    getLeaf(root->rchild, sum);
    return 0;
}

void clear(Node *node) {
    if (node->lchild != NULL) {
		clear(node->lchild);
    }
    if (node->rchild != NULL) {
        clear(node->rchild);
    }
    free(node);
}

int main() {
    Node *root = build_demo();
    height(root);
    int sum = 0;
    getLeaf(root, &sum);
    printf("leafs = %d\n", sum);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    clear(root);
    return 0;
}
