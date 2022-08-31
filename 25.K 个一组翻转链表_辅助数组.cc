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
            vector<ListNode*> v(k);
            int cnt = 0;
            ListNode* cur = head;
            while (cur != nullptr) {
                v[cnt] = cur;
                ++cnt;
                cur = cur->next;
                if (cnt == k) {
                    v[0]->next = nullptr;
                    for (int i = 1; i < k; ++i) {
                        v[i]->next = v[i-1];
                    }
                    last->next = v[k-1];
                    last = v[0];
                    v.clear();
                    cnt = 0;
                }
            }
            if (cnt != 0) {
                last->next = v[0];
                v.clear();
            }
            return dummy->next;
        }
    };
