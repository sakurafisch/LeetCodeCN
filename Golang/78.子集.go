package leetcode

import "math"

func subsets(nums []int) [][]int {
	l := len(nums)
	maxn := int(math.Pow(float64(2), float64(l)))
	ans := make([][]int, maxn, maxn)
	for i := 0; i < maxn; i++ {
		for j := 0; j < l; j++ {
			if ((i >> j) & 1) == 1 {
				ans[i] = append(ans[i], nums[j])
			}
		}
	}
	return ans
}
