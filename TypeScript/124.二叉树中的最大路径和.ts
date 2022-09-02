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

let ans: number = -1 << 63

function maxPathSum(root: TreeNode | null): number {
    ans = -1 << 63
    maxPath(root)
    return ans
};

function maxPath(root: TreeNode | null): number {
    if (root === null)
        return 0
    const left = Math.max(0, maxPath(root.left))
    const right = Math.max(0, maxPath(root.right))
    const newPath = root.val + left + right
    ans = Math.max(ans, newPath)
    return root.val + Math.max(left, right)
}
