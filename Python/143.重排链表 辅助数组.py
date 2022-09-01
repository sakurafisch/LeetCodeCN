from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if head is None:
            return
        arr: list[ListNode] = []
        while head is not None:
            arr.append(head)
            head = head.next
        left, right = 0, len(arr) - 1
        while left < right:
            arr[left].next = arr[right];
            left += 1
            if left == right:
                break
            arr[right].next = arr[left]
            right -= 1
        arr[left].next = None
