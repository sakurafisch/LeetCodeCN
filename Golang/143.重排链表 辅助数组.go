package leetcode

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func reorderList(head *ListNode) {
	if head == nil {
		return
	}
	arr := []*ListNode{}
	for head != nil {
		arr = append(arr, head)
		head = head.Next
	}
	left, right := 0, len(arr)-1
	for left < right {
		arr[left].Next = arr[right]
		left++
		if left == right {
			break
		}
		arr[right].Next = arr[left]
		right--
	}
	arr[left].Next = nil
}
