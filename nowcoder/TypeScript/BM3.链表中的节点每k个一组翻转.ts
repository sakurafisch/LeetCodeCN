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
 * @param head ListNode类 
 * @param k int整型 
 * @return ListNode类
 */
export function reverseKGroup(head: ListNode, k: number): ListNode {
    const dummy: ListNode = new ListNode(0, head)
    let last: ListNode = dummy
    let arr: Array<ListNode> = new Array<ListNode>(k)
    let cnt: number = 0
    let curr: ListNode = head
    while (curr != null) {
        arr[cnt] = curr
        ++cnt
        curr = curr.next
        if (cnt === k) {
            arr[0].next = null
            for (let i = 1; i < k; ++i) {
                arr[i].next = arr[i-1]
            }
            last.next = arr[k-1]
            last = arr[0]
            arr = new Array<ListNode>(k)
            cnt = 0
        }
    }
    if (cnt !== 0) {
        last.next = arr[0]
        arr = null
    }
    return dummy.next
}
