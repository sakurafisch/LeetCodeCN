package leetcode

import "sort"

func maxChunksToSorted(arr []int) int {
	ans := 0
	sum1, sum2 := 0, 0
	t := append([]int{}, arr...)
	sort.Slice(t, func(i, j int) bool { return t[i] < t[j] })
	for i := 0; i < len(arr); i++ {
		sum1 += arr[i]
		sum2 += t[i]
		if sum1 == sum2 {
			ans += 1
		}
	}
	return ans
}
