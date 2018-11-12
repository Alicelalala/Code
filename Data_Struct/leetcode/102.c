/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int **getResult (struct TreeNode *root, int **ret, int *cols, int k) {
    if (root == NULL) return;
    ret[k][cols[k]++] = root->val;
    getResult(root->left, ret, cols, k + 1);
    getResult(root->right, ret, cols, k + 1);
    return ;
}

int getHeight (struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = getHeight(root->left), r = getHeight(root->right);
    return (l > r ? l : r) + 1;
}

void getColumns (struct TreeNode *root, int *cols, int k) {
    if (root == NULL) return ;
    cols[k] += 1;
    getColumns(root->left, cols, k + 1);
    getColumns(root->right, cols, k + 1);
    return ;
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    *returnSize = getHeight(root);
    *columnSizes = (int *)calloc(sizeof(int), *returnSize); //初始化为0
    getColumns(root, *columnSizes, 0); //0当前层号
    int **ret = (int **)malloc(sizeof(int *) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        ret[i] = (int *)malloc(sizeof(int) * (*columnSizes)[i]);
        (*columnSizes)[i] = 0;
    }
    getResult(root, ret, *columnSizes, 0);
    return ret;
}
