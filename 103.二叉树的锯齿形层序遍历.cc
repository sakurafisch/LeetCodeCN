#include <vector>
#include <stack>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        stack<TreeNode*> s1, s2;
        s1.push(root);
        bool isLeftToRight = true;
        while (!s1.empty() || !s2.empty()) {
            vector<int> tmp;
            if (isLeftToRight) {
                while (!s1.empty()) {
                    auto node = s1.top(); s1.pop();
                    if (!node)
                        continue;
                    tmp.push_back(node->val);
                    if (node->left)
                        s2.push(node->left);
                    if (node->right)
                        s2.push(node->right);
                }
            }
            if (!isLeftToRight) {
                while (!s2.empty()) {
                    auto node = s2.top(); s2.pop();
                    if (!node)
                        continue;
                    tmp.push_back(node->val);
                    if (node->right)
                        s1.push(node->right);
                    if (node->left)
                        s1.push(node->left);
                }
            }
            if (!tmp.empty())
                ans.push_back(tmp);
            tmp.clear();
            isLeftToRight = !isLeftToRight;
        }
        return ans;
    }
};
