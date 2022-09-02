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
    bool isBalanced(TreeNode *root) {
        if (maxDepth(root) == -1)
            return false;
        return true;
    }

    int maxDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        if (left == -1 || right == -1 || left - right > 1 || right - left > 1)
            return -1;
        return 1 + max(left, right);
    }
};
