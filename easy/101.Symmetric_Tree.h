/*
Given a binary tree, isMirror whether it is a mirror of itself
(ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

1234243
3241423
3424321
 
But the following [1,2,2,nullptr,3,nullptr,3] is not:

    1
   / \
  2   2
   \   \
   3    3


Follow up: Solve it both recursively and iteratively.
*/

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
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
private:
    bool isMirror(TreeNode *t1, TreeNode *t2) {
        if (t1 == nullptr && t2 == nullptr) return true;
        if (t1 == nullptr || t2 == nullptr) return false;
        return (t1->val == t2->val) && (isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left));
    }
};

// 迭代
class Solution2 {
public:
    bool isMirror(TreeNode *u, TreeNode *v) {
        queue <TreeNode*> q;
        q.push(u); q.push(v);
        while (!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if (u == nullptr && v == nullptr) continue;
            if ((u ==nullptr || v == nullptr) || (u->val != v->val)) return false;

            q.push(u->left); 
            q.push(v->right);

            q.push(u->right); 
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};