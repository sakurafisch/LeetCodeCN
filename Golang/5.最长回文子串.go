package leetcode

func longestPalindrome(s string) string {
	if len(s) == 0 {
		return ""
	}
	ans := s[0:1]
	for i := 0; i < len(s)-1; i++ {
		tmp := midToSide(s, i, i)
		if len(tmp) > len(ans) {
			ans = tmp
		}
		tmp = midToSide(s, i, i+1)
		if len(tmp) > len(ans) {
			ans = tmp
		}
	}
	return ans

}

func midToSide(s string, left int, right int) string {
	for left >= 0 && right < len(s) && s[left] == s[right] {
		left--
		right++
	}
	return s[left+1 : right]
}
