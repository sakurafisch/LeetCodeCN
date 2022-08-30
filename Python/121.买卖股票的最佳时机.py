class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mi = 0x3f3f3f3f
        ans = 0
        for x in prices:
            ans = max(ans, x - mi)
            mi = min(mi, x)
        return ans
