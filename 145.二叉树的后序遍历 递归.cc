/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start

#include <iostream>
#include <vector>
using std::vector;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
        return ans;
    }
};
// @lc code=end

