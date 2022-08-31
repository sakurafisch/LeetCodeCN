
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
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            ListNode* pre = dummy;
            for (int i = 0; i < left-1; ++i) {
                pre = pre->next;
            }
            ListNode* curr = pre->next;
            ListNode* lat = curr->next;
            for (int i = left; i < right; ++i) {
                curr->next = lat->next;
                lat->next = pre->next;
                pre->next = lat;
                lat = curr->next;
            }
            return dummy->next;
        }
    };
