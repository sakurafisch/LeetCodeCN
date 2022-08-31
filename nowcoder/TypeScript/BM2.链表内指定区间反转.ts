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
 * @param m int整型 
 * @param n int整型 
 * @return ListNode类
 */
export function reverseBetween(head: ListNode, m: number, n: number): ListNode {
    const dummy = new ListNode(0)
    dummy.next = head
    let pre = dummy
    for (let i = 0; i < m-1; ++i) {
        pre = pre.next
    }
    let curr = pre.next
    let lat = curr.next
    for (let i = m; i < n; ++i) {
        curr.next = lat.next
        lat.next = pre.next
        pre.next = lat
        lat = curr.next
    }
    return dummy.next
}