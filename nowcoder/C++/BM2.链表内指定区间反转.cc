struct ListNode {
	int val;
	struct ListNode *next;
    ListNode(int x) : val(x) {}
};

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        for (int i = 0; i < m-1; ++i) {
            pre = pre->next;
        }
        ListNode* curr = pre->next;
        ListNode* lat = curr->next;
        for (int i = m; i < n; ++i) {
            curr->next = lat->next;
            lat->next = pre->next;
            pre->next = lat;
            lat = curr->next;
        }
        return dummy->next;
    }
};
