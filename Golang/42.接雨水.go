package leetcode

func trap(height []int) int {
	ans := 0
	n := len(height)
	if n == 0 {
		return ans
	}
	leftheight := make([]int, n, n)
	rightheight := make([]int, n, n)
	leftheight[0] = height[0]
	rightheight[n-1] = height[n-1]
	for i := 1; i < n; i++ {
		leftheight[i] = maxInt(leftheight[i-1], height[i])
	}
	for i := n - 2; i >= 0; i-- {
		rightheight[i] = maxInt(rightheight[i+1], height[i])
	}
	for i := 0; i < n; i++ {
		ans += minInt(leftheight[i], rightheight[i]) - height[i]
	}
	return ans
}

func minInt(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func maxInt(x, y int) int {
	if x > y {
		return x
	}
	return y
}
