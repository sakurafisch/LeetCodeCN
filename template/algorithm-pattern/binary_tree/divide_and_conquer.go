package binary_tree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type ResultType bool

func traversal(root *TreeNode) ResultType {
	// nil or leaf
	if root == nil {
		// do something and return
	}

	// Divide
	var left ResultType = traversal(root.Left)
	var right ResultType = traversal(root.Right)

	// Conquer
	var result ResultType = (left && right) // Merge from left and right

	return result
}

// 以下是示例

// 通过分治法遍历二叉树
func preorderTraversal(root *TreeNode) []int {
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

// 归并排序
func MergeSort(nums []int) []int {
	return mergeSort(nums)
}
func mergeSort(nums []int) []int {
	if len(nums) <= 1 {
		return nums
	}
	// 分治法：divide 分为两段
	mid := len(nums) / 2
	left := mergeSort(nums[:mid])
	right := mergeSort(nums[mid:])
	// 合并两段数据
	result := merge(left, right)
	return result
}

func merge(left, right []int) (result []int) {
	// 两边数组合并游标
	l := 0
	r := 0
	// 注意不能越界
	for l < len(left) && r < len(right) {
		// 谁小合并谁
		if left[l] > right[r] {
			result = append(result, right[r])
			r++
		} else {
			result = append(result, left[l])
			l++
		}
	}
	// 剩余部分合并
	result = append(result, left[l:]...)
	result = append(result, right[r:]...)
	return
}

// 快速排序
func QuickSort(nums []int) []int {
	// 思路：把一个数组分为左右两段，左段小于右段，类似分治法没有合并过程
	quickSort(nums, 0, len(nums)-1)
	return nums

}

// 原地交换，所以传入交换索引
func quickSort(nums []int, start int, end int) {
	if start < end {
		// 分治法：divide
		pivot := partition(nums, start, end)
		quickSort(nums, 0, pivot-1)
		quickSort(nums, pivot+1, end)
	}
}

// 分区
func partition(nums []int, start int, end int) int {
	p := nums[end]
	i := start
	for j := start; j < end; j++ {
		if nums[j] < p {
			swap(nums, i, j)
			i++
		}
	}
	// 把中间的值换为用于比较的基准值
	swap(nums, i, end)
	return i
}

func swap(nums []int, i, j int) {
	t := nums[i]
	nums[i] = nums[j]
	nums[j] = t
}
