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
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        vector<ListNode*> vec;
        while (head) {
            vec.emplace_back(head);
            head = head->next;
        }
        int left = 0, right = vec.size() - 1;
        while (left < right) {
            vec[left]->next = vec[right];
            ++left;
            if (left == right)
                break;
            vec[right]->next = vec[left];
            --right;
        }
        vec[left]->next = nullptr;
    }
};
