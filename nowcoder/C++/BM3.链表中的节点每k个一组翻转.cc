#include <vector>
using std::vector;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x) {}
    ListNode(int x, ListNode * next) : val(x), next(next) {}
    
};


class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* last = dummy;
        vector<ListNode*> v(k);
        int cnt = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            v[cnt] = curr;
            ++cnt;
            curr = curr->next;
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