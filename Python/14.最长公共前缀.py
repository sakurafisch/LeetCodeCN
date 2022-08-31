class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans: str = strs[0]
        for i in range(0, len(strs)):
            for j in range(0, len(ans)):
                if j == len(strs[i]) or ans[j] != strs[i][j]:
                    ans = ans[:j]
                    break
        return ans
