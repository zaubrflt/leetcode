#include "../../lib/BinaryTree.h"
#include <queue>

class Solution {
public:
  void flatten(TreeNode* root)
  {
    pushIntoQueue(root);
    TreeNode* head = new TreeNode();
    TreeNode* cur = head;
    while (nodeQueue.empty() == false) {
      TreeNode* node = nodeQueue.front();
      nodeQueue.pop();
      cur->left = nullptr;
      cur->right = node;
      cur = cur->right;
    }
    root = head->right;
    delete head;
  }
private:
  void pushIntoQueue(TreeNode* root)
  {
    if (root == nullptr) return;
    nodeQueue.push(root);
    pushIntoQueue(root->left);
    pushIntoQueue(root->right);
  }

  std::queue<TreeNode *> nodeQueue;
};

class Solution2 {
public:
  void flatten(TreeNode* root)
  {
    TreeNode* cur = root;
    while (cur) {
      if (cur->left) {
        TreeNode* rightOfLeft = cur->left;
        while (rightOfLeft->right) {
          rightOfLeft = rightOfLeft->right;
        }
        rightOfLeft->right = cur->right;
        cur->right = cur->left;
        cur->left = nullptr;
      }
      cur = cur->right;
    }
  }
};