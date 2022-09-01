from typing import List

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ans: List[int] = []
        if len(s) < len(p):
            return ans
        sts: List[int] = [0] * 26
        stp: List[int] = [0] * 26
        for i in range(len(p)):
            sts[ord(s[i]) - ord('a')] += 1
            stp[ord(p[i]) - ord('a')] += 1
        if sts == stp:
            ans.append(0)
        left: int = 0
        while left + len(p) < len(s):
            sts[ord(s[left]) - ord('a')] -= 1
            sts[ord(s[left + len(p)]) - ord('a')] += 1
            left += 1
            if (sts == stp):
                ans.append(left)
        return ans
