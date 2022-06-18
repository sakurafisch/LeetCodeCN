package leetcode

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	var dummy *ListNode = &ListNode{Val: 0, Next: head}
	var last = dummy
	var s [](*ListNode) = make([](*ListNode), k, k)
	var cnt int = 0
	var cur *ListNode = head
	for cur != nil {
		s[cnt] = cur
		cnt++
		cur = cur.Next
		if cnt == k {
			s[0].Next = nil
			for i := 1; i < k; i++ {
				s[i].Next = s[i-1]
			}
			last.Next = s[k-1]
			last = s[0]
			s = make([](*ListNode), k, k)
			cnt = 0
		}
	}
	if cnt != 0 {
		last.Next = s[0]
		s = nil
	}
	return dummy.Next
}
