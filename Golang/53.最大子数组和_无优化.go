package leetcode

import "math"

func maxSubArray(nums []int) int {
	dp := make([]int, len(nums), len(nums))
	dp[0] = nums[0]
	for i := 1; i < len(nums); i++ {
		if dp[i-1] > 0 {
			dp[i] = dp[i-1] + nums[i]
		} else {
			dp[i] = nums[i]
		}
	}
	ans := math.MinInt
	for _, v := range dp {
		ans = maxInt(ans, v)
	}
	return ans
}

func maxInt(x, y int) int {
	if x > y {
		return x
	}
	return y
}
