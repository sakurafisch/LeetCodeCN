#include <queue>
using namespace std;

// Definition for a binary tree node.
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            if (!node)
                continue;
            if (node->left)
                node->left->val += node->val;
                q.push(node->left);
            if (node->right)
                node->right->val += node->val;
                q.push(node->right);
            if (!node->left && !node->right)
                if (node->val == targetSum)
                    return true;
        }
        return false;
    }
};
