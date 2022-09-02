class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans: int = 0
        if len(s) == 0:
            return ans
        arr: list[bool] = [False] * 128
        left, right = 0, 0
        while right < len(s):
            if arr[ord(s[right])] == False:
                arr[ord(s[right])] = True
                ans = max(ans, right - left + 1)
                right += 1
            else:
                arr[ord(s[left])] = False
                left += 1
        return ans
