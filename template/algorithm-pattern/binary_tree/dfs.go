package binary_tree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func preorderTraversal(root *TreeNode) []int {
	result := make([]int, 0)
	dfs(root, &result)
	return result
}

// V1：深度遍历，结果指针作为参数传入到函数内部
func dfs(root *TreeNode, result *[]int) {
	if root == nil {
		return
	}
	*result = append(*result, root.Val)
	dfs(root.Left, result)
	dfs(root.Right, result)
}

// V2：通过分治法遍历
func preorderTraversal2(root *TreeNode) []int {
	result := divideAndConquer(root)
	return result
}
func divideAndConquer(root *TreeNode) []int {
	result := make([]int, 0)
	// 返回条件(null & leaf)
	if root == nil {
		return result
	}
	// 分治(Divide)
	left := divideAndConquer(root.Left)
	right := divideAndConquer(root.Right)
	// 合并结果(Conquer)
	result = append(result, root.Val)
	result = append(result, left...)
	result = append(result, right...)
	return result
}
