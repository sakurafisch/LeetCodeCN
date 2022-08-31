package main

// import . "nc_tools"

type ListNode struct {
	Val  int
	Next *ListNode
}

/**
 *
 * @param head ListNode类
 * @param m int整型
 * @param n int整型
 * @return ListNode类
 */
func reverseBetween(head *ListNode, m int, n int) *ListNode {
	var dummy *ListNode = &ListNode{Val: 0, Next: head}
	var pre *ListNode = dummy
	for i := 0; i < m-1; i++ {
		pre = pre.Next
	}
	var curr = pre.Next
	var lat = curr.Next
	for i := m; i < n; i++ {
		curr.Next = lat.Next
		lat.Next = pre.Next
		pre.Next = lat
		lat = curr.Next
	}
	return dummy.Next
}
