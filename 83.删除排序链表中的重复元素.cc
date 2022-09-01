#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        auto ptr = head;
        while (ptr->next != nullptr) {
            if (ptr->val == ptr->next->val) {
                ptr->next = ptr->next->next;
                continue;
            }
            ptr = ptr->next;
        }
        return head;
    }
};
