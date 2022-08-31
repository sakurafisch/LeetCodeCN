#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto cmp = [](const ListNode* x, const ListNode* y) -> bool { return x->val > y->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while (!pq.empty()) {
            ListNode* node = pq.top(); pq.pop();
            head->next = node;
            head = head->next;
            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }
        return dummy->next;
    }
};
