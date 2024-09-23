#include "../../lib/BinaryTree.h"

#include <vector>
#include <queue>
#include <deque>

class Solution {
public:
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root)
  {
    std::vector<std::vector<int>> ret;
    if (root == nullptr) return ret;
    std::queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    int floor = 1;
    while (nodeQueue.empty() == false) {
      int size = nodeQueue.size();
      std::deque<int> valDeque;
      for (int i = 0; i < size; i++) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();
        if (floor % 2 == 0) {
          valDeque.push_front(node->val);
        } else {
          valDeque.push_back(node->val);
        }
        if (node->left) nodeQueue.push(node->left);
        if (node->right) nodeQueue.push(node->right);
      }
      ret.emplace_back(std::vector<int>{valDeque.begin(), valDeque.end()});
      floor++;
    }
    return ret;
  }
};