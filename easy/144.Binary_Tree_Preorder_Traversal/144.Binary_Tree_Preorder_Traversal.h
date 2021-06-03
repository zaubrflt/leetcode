#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        __preorderTraversal(root);

        return res;
    }
private:
    void __preorderTraversal(TreeNode* root) {
        if (root == nullptr) return;

        res.push_back(root->val);
        if (root->left != nullptr) __preorderTraversal(root->left);
        if (root->right != nullptr) __preorderTraversal(root->right);
    }

    vector<int> res;
}; 

class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sq;
        TreeNode* tmp = root;

        while (tmp != nullptr || !sq.empty()) {
            while (tmp != nullptr) {
                res.push_back(tmp->val);
                sq.push(tmp);
                tmp = tmp->left;
            }
            tmp = sq.top();
            sq.pop();
            tmp = tmp->right;
        }
        return res;
    }
};