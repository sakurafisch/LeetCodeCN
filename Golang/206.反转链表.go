package leetcode

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseList(head *ListNode) *ListNode {
	var pre *ListNode = nil
	var cur *ListNode = head
	for cur != nil {
		var lat = cur.Next
		cur.Next = pre
		pre = cur
		cur = lat
	}
	return pre
}
