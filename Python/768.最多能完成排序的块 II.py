from typing import List

class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        ans: int = 0
        sum1, sum2 = 0, 0
        t: List[int] = arr.copy()
        t.sort()
        for i in range(len(arr)):
            sum1 += arr[i]
            sum2 += t[i]
            if sum1 == sum2:
                ans += 1
        return ans
