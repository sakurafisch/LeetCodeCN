#include <iostream>

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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *p, *q, *h, *t;
        p = head;
        q = head->next;
        h = q;
        while (p != nullptr && q != nullptr) {
            p->next = q->next;
            q->next = p;
            t = p;
            if (p->next != nullptr) {
                p = p->next;
            } else {
                return h;
            }
            if (p->next != nullptr) {
                q = p->next;
                t->next = q;
            } else {
                return h;
            }
        }
        return head;
    }
};