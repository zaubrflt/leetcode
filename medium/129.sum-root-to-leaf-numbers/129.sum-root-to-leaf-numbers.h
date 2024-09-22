#include "../../lib/BinaryTree.h"

class Solution {
public:
  int sumNumbers(TreeNode* root)
  {
    return doSum(root, 0);
  }
private:
  int doSum(TreeNode* root, int sum)
  {
    if (root == nullptr) return 0;
    int tmp = sum * 10 + root->val;
    if (root->left == nullptr && root->right == nullptr) {
      return tmp;
    } else {
      return doSum(root->left, tmp) + doSum(root->right, tmp);
    }
  }
};