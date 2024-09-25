#include "../../lib/BinaryTree.h"

#include <stdlib.h>
#include <algorithm>

class Solution {
public:
  int getMinimumDifference(TreeNode* root)
  {
    int ret = __INT32_MAX__;
    int pre = -1;
    scanTree(root, pre, ret);
    return ret;
  }
private:
  void scanTree(TreeNode* root, int& pre, int& ret)
  {
    if (root == nullptr) return;

    if (root->left) scanTree(root->left, pre, ret);
    if (pre != -1) {
      ret = std::min(ret, abs(pre - root->val));
    }
    pre = root->val;
    if (root->right) scanTree(root->right, pre, ret);
  }
};