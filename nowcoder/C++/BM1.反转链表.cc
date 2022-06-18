struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pre = nullptr;
        ListNode* cur = pHead;
        while (cur != nullptr) {
            ListNode* lat = cur->next;
            cur->next = pre;
            pre = cur;
            cur = lat;
        }
        return pre;
    }
};