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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* x, const ListNode* y) -> bool { return x->val > y->val; };
        auto pq = priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)>(cmp);
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        while (!pq.empty()) {
            ListNode* node = pq.top(); pq.pop();
            pre->next = node;
            pre = pre->next;
            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }
        return dummy->next;
    }
};
