package main

// import . "nc_tools"

type ListNode struct {
	Val  int
	Next *ListNode
}

/**
 *
 * @param pHead1 ListNode类
 * @param pHead2 ListNode类
 * @return ListNode类
 */
func Merge(pHead1 *ListNode, pHead2 *ListNode) *ListNode {
	var dummy *ListNode = &ListNode{}
	var curr *ListNode = dummy
	for pHead1 != nil && pHead2 != nil {
		if pHead1.Val < pHead2.Val {
			curr.Next = pHead1
			pHead1 = pHead1.Next
		} else {
			curr.Next = pHead2
			pHead2 = pHead2.Next
		}
		curr = curr.Next
	}
	if pHead1 != nil {
		curr.Next = pHead1
		return dummy.Next
	}
	curr.Next = pHead2
	return dummy.Next
}
