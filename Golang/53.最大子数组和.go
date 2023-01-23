package leetcode

func maxSubArray(nums []int) int {
	last, ans := 0, nums[0]
	for _, v := range nums {
		last = maxInt(last+v, v)
		ans = maxInt(ans, last)
	}
	return ans
}

func maxInt(x, y int) int {
	if x > y {
		return x
	}
	return y
}
