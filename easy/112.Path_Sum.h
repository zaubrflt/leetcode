/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such
that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

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

*/

#include <queue>

using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;

        if (root->left == nullptr && root->right == nullptr)
            return sum == root->val;
        
        bool lft = false, rht = false;
        if (root->left != nullptr) {
            lft = hasPathSum(root->left, sum - root->val);
        }
        if (root->right != nullptr) {
            rht = hasPathSum(root->right, sum - root->val);
        }

        return lft || rht;
    }
};

class Solution2 {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr) {
            return false;
        }
        queue<TreeNode *> que_node;
        queue<int> que_val;
        que_node.push(root);
        que_val.push(root->val);
        while (!que_node.empty()) {
            TreeNode *node = que_node.front();
            int tmp = que_val.front();
            que_node.pop();
            que_val.pop();
            if (node->left == nullptr && node->right == nullptr) {
                if (tmp == sum) return true;
                continue;
            }
            if (node->left != nullptr) {
                que_node.push(node->left);
                que_val.push(node->left->val + tmp);
            }
            if (node->right != nullptr) {
                que_node.push(node->right);
                que_val.push(node->right->val + tmp);
            }
        }
        return false;
    }
};