package nowcoder

// import . "nc_tools"
type ListNode struct {
	Val  int
	Next *ListNode
}

/**
 *
 * @param pHead ListNode类
 * @return ListNode类
 */
func ReverseList(pHead *ListNode) *ListNode {
	var pre *ListNode = nil
	var cur *ListNode = pHead
	for cur != nil {
		var lat = cur.Next
		cur.Next = pre
		pre = cur
		cur = lat
	}
	return pre
}
