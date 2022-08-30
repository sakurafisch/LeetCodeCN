# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        dummy = ListNode(0, head)
        pre = dummy
        for i in range(0, left-1):
            pre = pre.next
        curr = pre.next
        lat = curr.next
        for i in range(left, right):
            curr.next = lat.next
            lat.next = pre.next
            pre.next = lat
            lat = curr.next
        return dummy.next
