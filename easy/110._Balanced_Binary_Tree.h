/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ
in height by no more than 1.

Example 1:

      3
     / \
    9  20
       / \
      15  7

Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:

        1
       / \
      2   2
     / \
    3   3
   / \
  4   4

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:

Input: root = []
Output: true
 
Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
*/

#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    bool isBalanced(TreeNode* root) {
        return checkDepth(root) == -1 ? false : true;
    }
private:
    int checkDepth(TreeNode* node) {
        if (node == nullptr) return 0;
        int left = checkDepth(node->left);
        if (left == -1) return -1;
        int right = checkDepth(node->right);
        if (right == -1) return -1;

        return abs(checkDepth(node->left) - checkDepth(node->right)) > 1 ? -1 : 1 + std::max(left, right);
    }
};

class Solution2 {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        } else {
            return std::abs(height(root->left) - height(root->right)) <= 1 &&
                   isBalanced(root->left) && isBalanced(root->right);
        }
    }
private:
    bool height(TreeNode* node) {
        if (node == nullptr) return 0;
        else {
            return std::max(height(node->left), height(node->right)) + 1;
        }
    }
};