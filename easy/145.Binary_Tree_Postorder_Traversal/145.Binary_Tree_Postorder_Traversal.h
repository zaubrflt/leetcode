#include <vector>
#include <stack>

#include "TreeNode.h"

using namespace std;

class Solution1 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        __postorderTraversal(root);

        return res;
    }
private:
    void __postorderTraversal(TreeNode* root) {
        if (root == nullptr) return;

        if (root->left != nullptr) __postorderTraversal(root->left);
        if (root->right != nullptr) __postorderTraversal(root->right);
        res.push_back(root->val);
    }

    vector<int> res;
};

class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sq;
        TreeNode* tmp = root;
        TreeNode* prev = nullptr;

        while (tmp != nullptr || !sq.empty()) {
            while (tmp != nullptr) {
                sq.push(tmp);
                tmp = tmp->left;
            }
            tmp = sq.top();
            sq.pop();
            if (tmp->right == nullptr || tmp->right == prev) {
                res.push_back(tmp->val);
                prev = tmp;
                tmp = nullptr;
            } else {
                sq.push(tmp);
                tmp = tmp->right;
            }
        }
        return res;
    }
};