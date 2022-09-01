// Definition for singly-linked list.
class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}

function reorderList(head: ListNode | null): void {
    if (head === null) {
        return
    }
    const arr = new Array<ListNode>()
    while (head !== null) {
        arr.push(head)
        head = head.next
    }
    let [left, right] = [0, arr.length - 1]
    while (left < right) {
        arr[left].next = arr[right]
        ++left
        if (left == right) {
            break
        }
        arr[right].next = arr[left]
        --right
    }
    arr[left].next = null
};
