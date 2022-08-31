package leetcode

func lengthOfLongestSubstring(s string) int {
	ans := 0
	m := make(map[byte]bool)
	left, right := 0, 0
	for right < len(s) {
		if _, ok := m[s[right]]; !ok {
			m[s[right]] = true
			ans = max(ans, right-left+1)
			right++
		} else {
			delete(m, s[left])
			left++
		}
	}
	return ans
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}
