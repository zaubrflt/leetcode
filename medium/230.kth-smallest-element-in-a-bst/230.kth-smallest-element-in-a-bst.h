#include "../../lib/BinaryTree.h"

#include <vector>

class Solution {
public:
  int kthSmallest(TreeNode* root, int k)
  {
    std::vector<int> nodeVal;
    scanTree(root, nodeVal);
    return nodeVal[k - 1];
  }
private:
  void scanTree(TreeNode* node, std::vector<int>& nodeVal)
  {
    if (node == nullptr) return;
    scanTree(node->left, nodeVal);
    nodeVal.push_back(node->val);
    scanTree(node->right, nodeVal);
  }
};