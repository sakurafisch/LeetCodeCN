#include <vector>
using std::vector;

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* last = dummy;
        vector<ListNode*> vec(k);
        int cur = 0;
        while (head != nullptr) {
            vec[cur] = head;
            ++cur;
            head = head->next;
            if (cur == k) {
                vec[0]->next = nullptr;
                for (int i = 1; i < k; ++i) {
                    vec[i]->next = vec[i-1];
                }
                last->next = vec[k-1];
                last = vec[0];
                vec.clear();
                cur = 0;
            }
        }
        if (cur != 0) {
            last->next = vec[0];
            vec.clear();
        }
        return dummy->next;
    }
};
