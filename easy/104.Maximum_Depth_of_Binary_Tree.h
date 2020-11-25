/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path
from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
*/

#include <algorithm>
#include <queue>

using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 递归
class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// 迭代
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int cnt = 0, sz;
        queue <TreeNode*> q;
        TreeNode* tmp;
        q.push(root);
        while (!q.empty()) {
            sz = q.size();
            while (sz > 0) {
                tmp = q.front(); q.pop();
                if (tmp->left != nullptr) q.push(tmp->left);
                if (tmp->right != nullptr) q.push(tmp->right);
                sz -= 1;
            }
            cnt++;
        }
        return cnt;
    }
};