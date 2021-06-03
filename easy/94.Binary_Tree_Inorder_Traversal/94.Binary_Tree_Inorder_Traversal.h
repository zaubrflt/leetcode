#include <vector>
#include <stack>
#include <iostream>

#include "TreeNode.h"

using namespace std;

class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::cout << "into inorderTraversal" << std::endl;
        __inorderTraversal(root);
        std::cout << "leave inorderTraversal" << std::endl;
        return res;
    }
private:
    void __inorderTraversal(TreeNode* root) {
        std::cout << "into __inorderTraversal" << std::endl;
        if (root == nullptr) return;

        if (root->left != nullptr) __inorderTraversal(root->left);
        std::cout << "in node " << root->val <<std::endl;
        res.push_back(root->val);
        if (root->right != nullptr) __inorderTraversal(root->right);
        std::cout << "leave __inorderTraversal" << std::endl;
    }

    vector<int> res;
};

class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sq;
        TreeNode* tmp = root;

        while (tmp != nullptr || !sq.empty()) {
            while (tmp != nullptr) {
                sq.push(tmp);
                tmp = tmp->left;
            }
            tmp = sq.top();
            sq.pop();
            res.push_back(tmp->val);
            tmp = tmp->right;
        }
        return res;
    }
};