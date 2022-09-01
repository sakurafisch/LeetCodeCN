// Definition for singly-linked list.
class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    const h = new ListNode(0)
    let p = h
    let tmp = 0
    while (l1 != null && l2 != null) {
        p.next = new ListNode((l1.val + l2.val + tmp) % 10)
        tmp = (l1.val + l2.val + tmp) / 10
        tmp = Math.floor(tmp)
        p = p.next
        l1 = l1.next
        l2 = l2.next
    }
    while (l1 != null) {
        p.next = new ListNode((l1.val + tmp) % 10)
        tmp = (l1.val + tmp) / 10
        tmp = Math.floor(tmp)
        p = p.next
        l1 = l1.next
    }
    while (l2 != null) {
        p.next = new ListNode((l2.val + tmp) % 10)
        tmp = (l2.val + tmp) / 10
        tmp = Math.floor(tmp)
        p = p.next
        l2 = l2.next
    }
    if (tmp == 1)
        p.next = new ListNode(1)
    return h.next
};

(() => {
    const l1 = new ListNode(2, new ListNode(4, new ListNode(3)))
    const l2 = new ListNode(5, new ListNode(6, new ListNode(4)))
    const output = addTwoNumbers(l1, l2)
    let o = output
    while (o != null) {
        console.log(o.val);
        o = o.next
    }
})()
