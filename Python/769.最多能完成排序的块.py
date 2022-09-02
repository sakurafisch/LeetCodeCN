from typing import List
import sys

class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        ans: int = 0
        maxn = -sys.maxsize - 1
        for i in range(len(arr)):
            maxn = max(maxn, arr[i])
            if i == maxn:
                ans += 1
        return ans
