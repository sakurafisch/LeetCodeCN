/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* lat = nullptr;
        while (cur != nullptr) {
            lat = cur->next;
            cur->next = pre;
            pre = cur;
            cur = lat;
        }
        return pre;
    }
};
// @lc code=end

