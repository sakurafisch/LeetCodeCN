// Definition for singly-linked list.
class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}


function reverseBetween(head: ListNode | null, left: number, right: number): ListNode | null {
    const dummy = new ListNode(0, head)
    let pre = dummy
    for (let i = 0; i < left - 1; ++i) {
        pre = pre.next
    }
    let curr = pre.next
    let lat = curr.next
    for (let i = left; i < right; ++i) {
        curr.next = lat.next
        lat.next = pre.next
        pre.next = lat
        lat = curr.next
    }
    return dummy.next
};
