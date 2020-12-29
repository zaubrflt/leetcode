/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively.
Return 24.

*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution1 {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return root ? dfs(root) : 0;
    }
private:
    int dfs(TreeNode* root) {
        int sum = 0;
        if (root->left) {
            sum += isLeafNode(root->left) ? root->left->val : dfs(root->left);
        }
        if (root->right && !isLeafNode(root->right)) {
            sum += dfs(root->right);
        }
        return sum;
    }
    bool isLeafNode(TreeNode* node) {
        return (!node->left) && (!node->right);
    }
};