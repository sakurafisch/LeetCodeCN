class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
    }
}

function isBalanced(root: TreeNode | null): boolean {
    if (maxDepth(root) == -1)
        return false
    return true
};

function maxDepth(root: TreeNode | null): number {
    if (root === null)
        return 0
    const left: number = maxDepth(root.left)
    const right: number = maxDepth(root.right)
    if (left == -1 || right == -1 || left - right > 1 || right - left > 1)
        return -1
    return 1 + Math.max(left, right)
}
