class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) == 0:
            return ""
        ans: str = s[0]
        for i in range(len(s)-1):
            tmp = self.midToSize(s, i, i)
            if len(tmp) > len(ans):
                ans = tmp
            tmp = self.midToSize(s, i, i+1)
            if len(tmp) > len(ans):
                ans = tmp
        return ans

    def midToSize(self, s: str, left: int, right: int) -> str:
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return s[left+1:right]
