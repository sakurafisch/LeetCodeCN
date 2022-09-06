package leetcode

func minDistance(word1 string, word2 string) int {
	if len(word1) == 0 || len(word2) == 0 {
		return len(word1) + len(word2)
	}
	dp := make([][]int, 1+len(word1))
	for k := range dp {
		dp[k] = make([]int, 1+len(word2))
	}

	for i := 0; i <= len(word1); i++ {
		dp[i][0] = i
	}
	for j := 0; j <= len(word2); j++ {
		dp[0][j] = j
	}
	for i := 1; i <= len(word1); i++ {
		for j := 1; j <= len(word2); j++ {
			if word1[i-1] == word2[j-1] {
				dp[i][j] = dp[i-1][j-1]
			} else {
				dp[i][j] = 1 + minInt(dp[i-1][j], minInt(dp[i][j-1], dp[i-1][j-1]))
			}
		}
	}
	return dp[len(word1)][len(word2)]
}

func minInt(x int, y int) int {
	if x < y {
		return x
	}
	return y
}
