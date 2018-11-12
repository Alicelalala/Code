/*************************************************************************
	> File Name: 16.根据三元组数列建立二叉链表.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月27日 星期六 12时32分20秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct Node {
    char val;
    struct Node *left, *right;
} Node, *pNode;

pNode init_tree (char val) {
    pNode node = (pNode)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->val = val;
    return node;
}
/*
void output_1 (Node *root) {
    if (root == NULL) return ;
    printf("%c", root->val);
    if (root->left == NULL && root->right == NULL) return ;
    printf("(");
    output(root->left);
    if (root->right != NULL) {
        printf(",");
    }
    output(root->right);
    printf(")");
    return ;
}
*/
void output (Node *root) {
    if (root == NULL) return ;
    printf("%c ", root->val);
    output(root->left);
    output(root->right);
    return ;
}

pNode arrNode[30] = {0};

int main() {
    char buf[10];
    pNode root = NULL, p = NULL;
    while (scanf("%s", buf) != EOF) {
        //printf("***%c\n", buf[0]);
        if (buf[0] == buf[1] && buf[0] == '^') break ; 
        p = init_tree(buf[1]);
        arrNode[buf[1] - 'A'] = p;
        if (buf[0] == '^') {
            root = p;
            continue;
        }
        if (buf[2] == 'L') {
            arrNode[buf[0] - 'A']->left = p;
            continue;
        }
        if (buf[2] == 'R') {
            arrNode[buf[0] - 'A']->right = p;
            continue;
        }
    }
    output(root);
    printf("\n");
    return 0;
}

