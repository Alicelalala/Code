/*************************************************************************
	> File Name: 100.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月25日 星期四 19时14分29秒
 ************************************************************************/

#include <stdio.h>
//100 
bool isSameTree (Node *p, Node *q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val != q->val) return false;
    return true;
}

// 101
bool __isSymmetric (Node *p, NOde *q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val != q->val)  return false;
    return __isSymmetric(p->left, q->right) && __isSymmetric(p->right, q->left);
}

bool isSymmetric (Node *root) {
    if (root == NULL) return true;
    return __isSymmetric(root->left, root->right);
}

//104 


// 107


// 110

// --- 1
int getHeight (struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = getHeight(root->left), r = getHeight(root->right);
    return (l > r ? l : r) + 1;
}

bool isBalanced (struct TreeNode *root) {
    if (root == NULL) return true;
    int l = getHeight(root->left), r = getHeight(root->right);
    if (abs(l - r) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

// --- 2
int getHeight (struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = getHeight(root->left); 
    if (l < 0) return -2;
    int r = getHeight(root->right);
    if (abs(l - r) > 1) return -2;
    return (l > r ? l : r) + 1;
}

bool isBalanced (struct TreeNode *root) {
    if (root == NULL) return true;
    return getHeight(root) > 0;
}

//112  


//226 
str {
    if (root == NULL) return root;
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

//235

int guang (Node *root, Node *p, Node *q, Node **result) {
    if (root == NULL) return 0;
    int ret = (root == p || root == q)
    ret += guang(root->left, p, q, result);
    if (ret == 2 && *result == NULL) *result = root;
    ret += guang(root->right, p, q, result);
    if (ret == 2 && *result == NULL) *result = root;
    return ret;
}

lowest () {
    Node *result = NULL;
    guang(root, p, q, &result);
    return result;
}

//257 

// 297  


