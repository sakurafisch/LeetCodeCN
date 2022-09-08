package binary_tree

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 前序遍历递归版
func preorderTraversal(root *TreeNode) {
	if root == nil {
		return
	}
	// 先访问根再访问左右
	fmt.Println(root.Val)
	preorderTraversal(root.Left)
	preorderTraversal(root.Right)
}

// 前序遍历迭代版
func preorderTraversal2(root *TreeNode) []int {
	if root == nil {
		return nil
	}
	result := make([]int, 0)
	stack := make([]*TreeNode, 0)

	for root != nil || len(stack) != 0 {
		for root != nil {
			// 前序遍历，所以先保存结果
			result = append(result, root.Val)
			stack = append(stack, root)
			root = root.Left
		}
		// pop
		node := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		root = node.Right
	}
	return result
}

// 中序遍历迭代版
func inorderTraversal(root *TreeNode) []int {
	result := make([]int, 0)
	if root == nil {
		return result
	}
	stack := make([]*TreeNode, 0)
	for len(stack) > 0 || root != nil {
		for root != nil {
			stack = append(stack, root)
			root = root.Left // 一直向左
		}
		// 弹出
		val := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		result = append(result, val.Val)
		root = val.Right
	}
	return result
}

// 后序遍历迭代版
func postorderTraversal(root *TreeNode) []int {
	// 通过lastVisit标识右子节点是否已经弹出
	if root == nil {
		return nil
	}
	result := make([]int, 0)
	stack := make([]*TreeNode, 0)
	var lastVisit *TreeNode
	for root != nil || len(stack) != 0 {
		for root != nil {
			stack = append(stack, root)
			root = root.Left
		}
		// 这里先看看，先不弹出
		node := stack[len(stack)-1]
		// 根节点必须在右节点弹出之后，再弹出
		if node.Right == nil || node.Right == lastVisit {
			stack = stack[:len(stack)-1] // pop
			result = append(result, node.Val)
			// 标记当前这个节点已经弹出过
			lastVisit = node
		} else {
			root = node.Right
		}
	}
	return result
}
