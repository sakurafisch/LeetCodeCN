/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val) {
            return head->next;
        }
        ListNode* ptr = head;
        while (ptr->next != nullptr) {
            if (ptr->next->val == val) {
                ptr->next = ptr->next->next;
                break;
            }
            ptr = ptr->next;
        }
        return head;
    }
};
