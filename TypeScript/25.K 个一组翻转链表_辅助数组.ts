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
    let last: ListNode = dummy;
    let arr = new Array<ListNode>(k);
    let cur: number = 0;
    while (head != null) {
        arr[cur] = head;
        ++cur;
        head = head.next;
        if (cur == k) {
            arr[0].next = null;
            for (let i = 1; i < k; ++i) {
                arr[i].next = arr[i-1];
            }
            last.next = arr[k-1];
            last = arr[0];
            arr = new Array<ListNode>(k);
            cur = 0;
        }
    }
    if (cur != 0) {
        last.next = arr[0];
    }
    return dummy.next;
};
