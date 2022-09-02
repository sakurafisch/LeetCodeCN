package leetcode

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxPathSum(root *TreeNode) int {
	ans := -1 << 31
	maxPath(root, &ans)
	return ans
}

func maxPath(root *TreeNode, final_ans *int) int {
	if root == nil {
		return 0
	}
	left := maxInt(0, maxPath(root.Left, final_ans))
	right := maxInt(0, maxPath(root.Right, final_ans))
	newPath := root.Val + left + right
	*final_ans = maxInt(*final_ans, newPath)
	return root.Val + maxInt(left, right)
}

func maxInt(x int, y int) int {
	if x > y {
		return x
	}
	return y
}
