package leetcode

func lengthOfLongestSubstring(s string) int {
	if len(s) == 0 {
		return 0
	}
	ans := 0
	arr := [128]bool{}
	left, right := 0, 0
	for right < len(s) {
		if arr[s[right]] == false {
			arr[s[right]] = true
			ans = maxInt(ans, right-left+1)
			right++
		} else {
			arr[s[left]] = false
			left++
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
