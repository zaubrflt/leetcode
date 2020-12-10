/*
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

*/

#include <algorithm>
#include <stack>
#include <queue>

using std::stack;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution1 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        TreeNode *tmp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = tmp;
        return root;
    }
};

class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;

        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            std::swap(node->left, node->right);
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return root;
    }
};

class Solution3 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            for (int i = 0; i < q.size(); ++i) {
                TreeNode* node = q.front();
                q.pop();
                std::swap(node->left, node->right);
                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
            }
        }
        return root;
    }
};