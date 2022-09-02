package leetcode

func maxChunksToSorted(arr []int) int {
	ans := 0
	maxn := -1 << 31
	for k, v := range arr {
		maxn = maxInt(maxn, v)
		if k == maxn {
			ans++
		}
	}
	return ans
}

func maxInt(x int, y int) int {
	if x > y {
		return x
	}
	return y
}
