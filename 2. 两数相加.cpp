
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h = new ListNode(0);
        ListNode* p = h;
        int tmp = 0;
        while (l1 && l2) {
            p->next = new ListNode((l1->val + l2->val + tmp) % 10);
            tmp = (l1->val + l2->val + tmp) / 10;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            p->next = new ListNode((l1->val + tmp) %10);
            tmp = (l1->val + tmp) / 10;
            p = p->next;
            l1 = l1->next;
        }
        while (l2) {
            p->next = new ListNode((l2->val + tmp) % 10);
            tmp = (l2->val + tmp) / 10;
            p = p->next;
            l2 = l2->next;
        }
        if (tmp) {
            p->next = new ListNode(1);
        }
        return h->next;
    }
};
