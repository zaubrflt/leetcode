#include "../../lib/BinaryTree.h"

#include <vector>

class Solution {
public:
  std::vector<int> rightSideView(TreeNode* root)
  {
    std::vector<int> ret;
    doView(root, 1, ret);
    return ret;
  }
private:
  void doView(TreeNode* node, int floor, std::vector<int>& ret)
  {
    if (node == nullptr) return;
    if (ret.size() < floor) {
      ret.push_back(node->val);
    } else {
      ret[floor - 1] = node->val;
    }
    if (node->left) {
      doView(node->left, floor + 1, ret);
    }
    if (node->right) {
      doView(node->right, floor + 1, ret);
    }
  }
};