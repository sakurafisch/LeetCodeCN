// Definition for singly-linked list.
class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.next = (next===undefined ? null : next)
    }
}

function reverseList(head: ListNode | null): ListNode | null {
    let pre = null
    let cur = head
    while (cur != null) {
        const lat = cur.next
        cur.next = pre
        pre = cur
        cur = lat
    }
    return pre
};
