package leetcode

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	dummy := &ListNode{Val: 0, Next: head}
	last := dummy
	arr := make([]*ListNode, k)
	cur := 0
	for head != nil {
		arr[cur] = head
		cur++
		head = head.Next
		if cur == k {
			arr[0].Next = nil
			for i := 1; i < k; i++ {
				arr[i].Next = arr[i-1]
			}
			last.Next = arr[k-1]
			last = arr[0]
			arr = make([]*ListNode, k)
			cur = 0
		}
	}
	if cur != 0 {
		last.Next = arr[0]
	}
	return dummy.Next
}
