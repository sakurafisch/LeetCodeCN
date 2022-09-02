#include <algorithm>

using std::max;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int final_ans = INT_MIN;
        maxPath(root, final_ans);
        return final_ans;
    }

    int maxPath(TreeNode* root, int& final_ans) {
        if (root == nullptr)
            return 0;
        int left = max(maxPath(root->left, final_ans), 0);
        int right = max(maxPath(root->right, final_ans), 0);
        int newPath = root->val + left + right;
        final_ans = max(final_ans, newPath);
        return root->val + max(left, right);
    }
};
