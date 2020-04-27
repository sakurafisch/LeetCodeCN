/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> sta;
        sta.push(root);
        sta.push(root);
        while(!sta.empty()) {
            TreeNode* left = sta.top(); sta.pop();
            TreeNode* right = sta.top(); sta.pop();
            if (!left && !right) continue;
            if (!left || !right || left->val != right->val) return false;
            sta.push(left->left);
            sta.push(right->right);
            sta.push(left->right);
            sta.push(right->left);
        }
        return true;
    }
};
// @lc code=end

