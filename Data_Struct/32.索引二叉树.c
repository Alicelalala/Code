/*************************************************************************
	> File Name: 32.索引二叉树.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月06日 星期日 19时28分37秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *lchild, *rchild, *father;
}Node;

Node* init(int value, Node *father) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->lchild = NULL;
    node->rchild = NULL;
    node->father = father;
    return node;
}

Node* insert(Node *node, int value) {
    if (node == NULL) {
        node = init(value, NULL);
    } else if (value > node->value) {
        if (node->rchild == NULL) {
            node->rchild = init(value, node);
        } else {
            node->rchild = insert(node->rchild, value);
        }
    } else {
        if (node->lchild == NULL) {
            node->lchild = init(value, node);
        } else {
            node->lchild = insert(node->lchild, value);
        }
    }
    return node;
}

Node* search(Node *node, int value) {
    if (node == NULL || node->value == value) return node;
    if (value > node->value) {
        search(node->rchild, value);
    } else {
        search(node->lchild, value);
    }
}

void dfs(Node *node) {
    if (node == NULL) return ;
    dfs(node->lchild);
    printf("%d ", node->value);
    dfs(node->rchild);
}

void clear(Node *node) {
    if (node != NULL) {
        if (node->lchild != NULL) {
            clear(node->lchild);
        }
        if (node->rchild != NULL) {
            clear(node->rchild);
        }
        free(node);
    }
}

int main() {
    Node *binarytree = NULL;
    init(100, binarytree);
    int n, num, value;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        binarytree = insert(binarytree, num);
    }
    scanf("%d", &value);
    if (search(binarytree, value) != NULL) {
        printf("search seccess!\n");
    } else {
        printf("search failed!\n");
    }
    dfs(binarytree);
    clear(binarytree);
    return 0;
}
