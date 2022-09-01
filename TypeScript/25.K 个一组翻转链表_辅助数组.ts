// Definition for singly-linked list.
class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}

function reverseKGroup(head: ListNode | null, k: number): ListNode | null {
    const dummy = new ListNode(0, head);
    let last = dummy
    let arr: Array<ListNode> = new Array<ListNode>(k)
    let cnt = 0;
    let cur = head
    while (cur != null) {
        arr[cnt] = cur
        ++cnt
        cur = cur.next
        if (cnt == k) {
            arr[0].next = null
            for (let i = 1; i < k; ++i) {
                arr[i].next = arr[i - 1]
            }
            last.next = arr[k - 1]
            last = arr[0]
            arr = new Array<ListNode>(k)
            cnt = 0
        }
    }
    if (cnt != 0) {
        last.next = arr[0]
        arr = null
    }
    return dummy.next
};
