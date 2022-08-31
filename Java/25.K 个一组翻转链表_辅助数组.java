package Java;

// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0, head);
        ListNode last = dummy;
        ListNode[] arr = new ListNode[k];
        int cnt = 0;
        ListNode cur = head;
        while (cur != null) {
            arr[cnt] = cur;
            ++cnt;
            cur = cur.next;
            if (cnt == k) {
                arr[0].next = null;
                for (int i = 1; i < k; ++i) {
                    arr[i].next = arr[i-1];
                }
                last.next = arr[k-1];
                last = arr[0];
                arr = new ListNode[k];
                cnt = 0;
            }
        }
        if (cnt != 0) {
            last.next = arr[0];
            arr = null;
        }
        return dummy.next;
    }
}
