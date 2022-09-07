class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()
        words: list[str] = s.split()
        ans: str = ""
        for i in range(len(words)-1, -1, -1):
            ans += words[i] + ' '
        return ans[:-1]
