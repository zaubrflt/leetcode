#include "../../lib/BinaryTree.h"

#include <vector>
#include <queue>

class Solution {
public:
  std::vector<std::vector<int>> levelOrder(TreeNode* root)
  {
    std::vector<std::vector<int>> ret;
    if (root == nullptr) return ret;
    std::queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    while (nodeQueue.empty() == false) {
      int size = nodeQueue.size();
      std::vector<int> floorArr(size);
      for (int i = 0; i < size; i++) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();
        floorArr[i] = node->val;
        if (node->left) nodeQueue.push(node->left);
        if (node->right) nodeQueue.push(node->right);
      }
      ret.push_back(floorArr);
    }
    return ret;
  }
};