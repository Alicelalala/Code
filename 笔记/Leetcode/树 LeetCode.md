### 树 LeetCode

##### leetcode100

```C
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
```

```c
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
```



##### leetcode101

```c
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
```

```c
bool __isSymmetric(struct TreeNode *p, struct TreeNode *q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val != q->val) return false;
    return __isSymmetric(p->left, q->right) && __isSymmetric(p->right, q->left);
}


bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    return __isSymmetric(root->left, root->right);
}
```



##### leetcode102

```c
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
 ]
```

```c
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
    if (root == NULL) return 0;
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
```



##### leetcode107

```c
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
```

```c
void getResult (struct TreeNode *root, int **ret, int *cols, int k) {
    if (root == NULL) return ;
    ret[k][cols[k]++] = root->val;
    getResult(root->left, ret, cols, k - 1);
    getResult(root->right, ret, cols, k - 1);
    return ;
}


int getHeight (struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = getHeight(root->left), r = getHeight(root->right);
    return (l > r ? l : r) + 1;
}

void getColumns (struct TreeNode *root, int *cols, int k) {
    if (root == NULL) return ;
    cols[k]++;
    getColumns(root->left, cols, k + 1);
    getColumns(root->right, cols, k + 1);
    return ;
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    *returnSize = getHeight(root);
    *columnSizes = (int *)calloc(sizeof(int), (*returnSize));
    getColumns(root, *columnSizes, 0);
    int **ret = (int **)malloc(sizeof(int *) * (*returnSize));
    int n = *returnSize - 1;
    for (int i = 0; i < *returnSize; i++) {
        ret[i] = (int *)malloc(sizeof(int) * (*columnSizes)[n]);
        (*columnSizes)[n--] = 0;
    }
    getResult(root, ret, *columnSizes, (*returnSize) - 1);
    return ret;
}
```





##### leetcode110[Balanced Binary Tree]

```c
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
```

```c
int getHeight (struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = getHeight(root->left);
    //printf("%d", l);
    if (l < 0) return -2;
    int r = getHeight(root->right);
    if (abs(l - r) > 1) return -2;
    return (l > r ? l : r) + 1;
}

bool isBalanced (struct TreeNode *root) {
    if (root == NULL) return true;
    return getHeight(root) > 0;
}
```



##### leetcode111

```c
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
```

```c
int minDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    else if (root->left == NULL) return 1 + minDepth(root->right);
    else if (root->right == NULL) return 1 + minDepth(root->left);
    else return 1 + (minDepth(root->left) < minDepth(root->right) ? minDepth(root->left) : minDepth(root->right));
}
```





##### leetcode112

```c
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

```

```c
bool hasPathSum(struct TreeNode* root, int sum) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL && sum - root->val == 0) return 1;
    else {
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
}
```





##### leetcode226

```c
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
```

```c
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) return root;
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
```





##### leetcode235

```c
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself 
             according to the LCA definition.
```

```c
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) return root;
    if (p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
    else if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
    return root;
}
```

