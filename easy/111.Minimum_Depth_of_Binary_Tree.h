/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path
from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example 1:

      3
     / \
    9  20
       / \
      15  7

Input: root = [3,9,20,null,null,15,7]
Output: 2

Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
 
Constraints:

The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000
*/

#include <algorithm>
#include <climits>
#include <queue>

using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 深度优先搜索
class Solution1 {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;

        int min_depth = INT_MAX;
        if (root->left != nullptr) {
            min_depth = std::min(minDepth(root->left), min_depth);
        }
        if (root->right != nullptr) {
            min_depth = std::min(minDepth(root->right), min_depth);
        }
        return min_depth + 1;
    }
};

// 广度优先搜索的性质保证了最先搜索到的叶子节点的深度一定最小
class Solution2 {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<std::pair<TreeNode*, int>> q;
        q.emplace(root, 1);
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (node->left == nullptr && node->right) return depth;
            if (node->left != nullptr) q.emplace(node->left, depth + 1);
            if (node->right != nullptr) q.emplace(node->right, depth + 1);
        }

        return 0;
    }    
};