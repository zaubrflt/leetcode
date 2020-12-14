/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3

*/

#include <vector>
#include <queue>
#include <string>

using std::vector;
using std::string;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution1 {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        getPath(root, "", paths);
        return paths;
    }
private:
    void getPath(TreeNode* node, string path, vector<string>& paths) {
        if (node != nullptr) {
            if (node->right == nullptr && node->left == nullptr) {
                path = path + std::to_string(node->val);
                paths.push_back(path);
            } else {
                path = path + std::to_string(node->val) + "->";
                getPath(node->left, path, paths);
                getPath(node->right, path, paths);
            }
        }
    }
};

class Solution2 {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;

        if (root == nullptr) {
            return paths;
        }

        queue<TreeNode*> node_queue;
        queue<string> path_queue;

        node_queue.push(root);
        path_queue.push(std::to_string(root->val));
        while (!node_queue.empty()) {
            TreeNode* node = node_queue.front();
            string path = path_queue.front();
            node_queue.pop();
            path_queue.pop();

            if (node->left == nullptr && node->right == nullptr) {
                paths.push_back(path);
            } else {
                if (node->left != nullptr) {
                    node_queue.push(node->left);
                    path_queue.push(path + "->" + std::to_string(node->left->val));
                }
                if (node->right != nullptr) {
                    node_queue.push(node->right);
                    path_queue.push(path + "->" + std::to_string(node->right->val));
                }
            }
        }
        return paths;
    }
};