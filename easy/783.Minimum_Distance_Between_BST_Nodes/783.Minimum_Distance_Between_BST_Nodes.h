#include <climits>
#include <algorithm>
#include <vector>

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
    int minDiffInBST(TreeNode* root) {
        __minDiffInBST(root);
        int minDiff = INT_MAX;
        for (int i = 0; i < values.size() - 1; ++i) {
            minDiff = min(minDiff, (values[i + 1] - values[i]));
        }
        return minDiff;
    }
private:
    vector<int> values;

    void __minDiffInBST(TreeNode* node) {
        if (node->left != nullptr) {
            __minDiffInBST(node->left);
        }
        values.push_back(node->val);
        if (node->right != nullptr) {
            __minDiffInBST(node->right);
        }
    }
};

class Solution2 {
public:
    int minDiffInBST(TreeNode* root) {
        int pre = -1, ans = INT_MAX;
        
        __minDiffInBST(root, pre, ans);

        return ans;
    }
private:
    void __minDiffInBST(TreeNode* node, int& pre, int& ans) {
        if (node->left != nullptr) {
            __minDiffInBST(node->left, pre, ans);
        }
        if (pre == -1) {
            pre = node->val;
        } else {
            ans = min(ans, node->val - pre);
            pre = node->val;
        }
        if (node->right != nullptr) {
            __minDiffInBST(node->right, pre, ans);
        }
    }
};