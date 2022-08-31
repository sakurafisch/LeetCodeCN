class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        for i in range(0, len(haystack) - len(needle) + 1):
            match: bool = True
            for j in range(0, len(needle)):
                if i + j == len(haystack):
                    return -1
                if haystack[i + j] != needle[j]:
                    match = False
                    break
            if match:
                return i
        return -1