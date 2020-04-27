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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode* l3 = new ListNode(min(l1->val, l2->val));
        ListNode *ptr3 = l3;
        ListNode *ptr1 = l1->val < l2->val ? l1->next : l1;
        ListNode* ptr2 = l1->val < l2->val ? l2 : l2->next;
        while (ptr1 != NULL && ptr2 != NULL) {
                if (ptr1->val < ptr2->val) {
                    ptr3->next = new ListNode(ptr1->val);
                    ptr1 = ptr1->next;
                    ptr3 = ptr3->next;
                } else {
                    ptr3->next = new ListNode(ptr2->val);
                    ptr2 = ptr2->next;
                    ptr3 = ptr3->next;
                }
        }
        while (ptr1 != NULL) {
            ptr3->next = new ListNode(ptr1->val);
            ptr1 = ptr1->next;
            ptr3 = ptr3->next;
        }
        while (ptr2 != NULL) {
            ptr3->next = new ListNode(ptr2->val);
            ptr2 = ptr2->next;
            ptr3 = ptr3->next;
        }
        return l3;
    }
};
