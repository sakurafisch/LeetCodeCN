package leetcode

func longestCommonPrefix(strs []string) string {
	ans := strs[0]
	for i := 0; i < len(strs); i++ {
		for j := 0; j < len(ans); j++ {
			if j == len(strs[i]) || ans[j] != strs[i][j] {
				ans = ans[:j]
				break
			}
		}
	}
	return ans
}
