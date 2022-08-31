function longestCommonPrefix(strs: string[]): string {
    let ans: string = strs[0];
    for (let i = 0; i < strs.length; ++i) {
        for (let j = 0; j < ans.length; ++j) {
            if (j === strs[i].length || ans[j] !== strs[i][j]) {
                ans = ans.slice(0, j);
                break;
            }
        }
    }
    return ans;
};
