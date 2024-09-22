#include "../../lib/BinaryTree.h"

#include <vector>
#include <queue>

class Solution {
public:
  std::vector<double> averageOfLevels(TreeNode* root)
  {
    std::vector<double> ret;
    std::queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    int floor = 1;
    while (nodeQueue.empty() == false) {
      double sum = 0;
      int size = nodeQueue.size();
      for (int i = 0; i < size; i++) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();
        sum += node->val;
        if (node->left) nodeQueue.push(node->left);
        if (node->right) nodeQueue.push(node->right);
      }
      ret.push_back(sum / size);
    }
    return ret;
  }
};