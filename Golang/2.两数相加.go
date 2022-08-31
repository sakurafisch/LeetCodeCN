package leetcode

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	h := &ListNode{Val: 0}
	p := h
	tmp := 0
	for l1 != nil && l2 != nil {
		p.Next = &ListNode{Val: (l1.Val + l2.Val + tmp) % 10}
		tmp = (l1.Val + l2.Val + tmp) / 10
		p = p.Next
		l1 = l1.Next
		l2 = l2.Next
	}
	for l1 != nil {
		p.Next = &ListNode{Val: (l1.Val + tmp) % 10}
		tmp = (l1.Val + tmp) / 10
		p = p.Next
		l1 = l1.Next
	}
	for l2 != nil {
		p.Next = &ListNode{Val: (l2.Val + tmp) % 10}
		tmp = (l2.Val + tmp) / 10
		p = p.Next
		l2 = l2.Next
	}
	if tmp == 1 {
		p.Next = &ListNode{Val: 1}
	}
	return h.Next
}
