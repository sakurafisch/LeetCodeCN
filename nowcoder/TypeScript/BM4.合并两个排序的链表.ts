class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.next = (next===undefined ? null : next)
    }
}

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 * 
 * @param pHead1 ListNode类 
 * @param pHead2 ListNode类 
 * @return ListNode类
 */
 export function Merge(pHead1: ListNode, pHead2: ListNode): ListNode {
    const dummy = new ListNode(0)
    let curr = dummy
    while (pHead1 !== null && pHead2 !== null) {
        if (pHead1.val < pHead2.val) {
            curr.next = pHead1
            pHead1 = pHead1.next
        } else {
            curr.next = pHead2
            pHead2 = pHead2.next
        }
        curr = curr.next
    }
    if (pHead1 !== null) {
        curr.next = pHead1
        return dummy.next
    }
    curr.next = pHead2
    return dummy.next
}
