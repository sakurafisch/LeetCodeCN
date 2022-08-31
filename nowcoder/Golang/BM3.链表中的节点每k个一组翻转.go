package main

// import . "nc_tools"

type ListNode struct {
	Val  int
	Next *ListNode
}

/**
 *
 * @param head ListNode类
 * @param k int整型
 * @return ListNode类
 */
func reverseKGroup(head *ListNode, k int) *ListNode {
	var dummy *ListNode = &ListNode{Val: 0, Next: head}
	var last *ListNode = dummy
	var arr [](*ListNode) = make([](*ListNode), k, k)
	var cnt int = 0
	var curr = head
	for curr != nil {
		arr[cnt] = curr
		cnt++
		curr = curr.Next
		if cnt == k {
			arr[0].Next = nil
			for i := 1; i < k; i++ {
				arr[i].Next = arr[i-1]
			}
			last.Next = arr[k-1]
			last = arr[0]
			arr = make([](*ListNode), k, k)
			cnt = 0
		}
	}
	if cnt != 0 {
		last.Next = arr[0]
		arr = nil
	}
	return dummy.Next
}
