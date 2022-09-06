function minDistance(word1: string, word2: string): number {
    if (word1.length == 0 || word2.length == 0)
        return word1.length + word2.length
    const dp = [...new Array(1 + word1.length)].map(_ => new Array(1 + word2.length).fill(0))
    for (let i = 0; i <= word1.length; ++i)
        dp[i][0] = i
    for (let j = 0; j <= word2.length; ++j)
        dp[0][j] = j
    for (let i = 1; i <= word1.length; ++i)
        for (let j = 1; j <= word2.length; ++j)
            if (word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1]
            else
                dp[i][j] = 1 + Math.min(dp[i-1][j], Math.min(dp[i][j-1], dp[i-1][j-1]))
    return dp.pop().pop()
    // return dp[word1.length][word2.length]
};
