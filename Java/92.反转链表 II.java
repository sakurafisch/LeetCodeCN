package Java;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummy = new ListNode(0, head);
        ListNode pre = dummy;
        for (int i = 0; i < left-1; ++i) {
            pre = pre.next;
        }
        ListNode curr = pre.next;
        ListNode lat = curr.next;
        for (int i = left; i < right; ++i) {
            curr.next = lat.next;
            lat.next = pre.next;
            pre.next = lat;
            lat = curr.next;
        }
        return dummy.next;
    }
}
