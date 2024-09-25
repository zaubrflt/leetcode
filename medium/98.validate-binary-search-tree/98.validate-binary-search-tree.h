#include "../../lib/BinaryTree.h"

#include <stack>

class Solution {
public:
  bool isValidBST(TreeNode* root)
  {
    std::stack<TreeNode*> nodeStack;
    int64_t pre = (int64_t)INT32_MIN - 1;
    while (nodeStack.empty() == false || root) {
      while (root) {
        nodeStack.push(root);
        root = root->left;
      }
      root = nodeStack.top();
      nodeStack.pop();
      if (root->val <= pre) {
        return false;
      }
      pre = root->val;
      root = root->right;
    }
    return true;
  }
};