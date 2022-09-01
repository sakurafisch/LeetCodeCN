from typing import Optional, List

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy: ListNode = ListNode(0, head)
        last: ListNode = dummy
        arr: List[ListNode] = [None] * k
        cur: int = 0
        while head is not None:
            arr[cur] = head
            cur += 1
            head = head.next
            if cur == k:
                arr[0].next = None
                for i in range(1, k):
                    arr[i].next = arr[i-1]
                last.next = arr[k-1]
                last = arr[0]
                arr = [None] * k
                cur = 0
        if cur != 0:
            last.next = arr[0]
            del arr
        return dummy.next
