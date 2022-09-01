package leetcode

func findAnagrams(s string, p string) []int {
	var ans []int
	if len(s) < len(p) {
		return ans
	}
	var sts [26]int
	var stp [26]int
	for i := 0; i < len(p); i++ {
		sts[s[i]-'a']++
		stp[p[i]-'a']++
	}
	if sts == stp {
		ans = append(ans, 0)
	}
	left := 0
	for left+len(p) < len(s) {
		sts[s[left]-'a']--
		sts[s[left+len(p)]-'a']++
		left++
		if sts == stp {
			ans = append(ans, left)
		}
	}
	return ans
}
