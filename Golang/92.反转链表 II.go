package leetcode

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseBetween(head *ListNode, left int, right int) *ListNode {
	var dummy *ListNode = &ListNode{Val: 0, Next: head}
	var pre *ListNode = dummy
	for i := 0; i < left-1; i++ {
		pre = pre.Next
	}
	var curr *ListNode = pre.Next
	var lat *ListNode = curr.Next
	for i := left; i < right; i++ {
		curr.Next = lat.Next
		lat.Next = pre.Next
		pre.Next = lat
		lat = curr.Next
	}
	return dummy.Next
}
