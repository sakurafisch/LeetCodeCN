from typing import List
from bisect import bisect_left, bisect_right

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if target not in nums:
            return [-1, -1]
        left = bisect_left(nums, target)
        right = bisect_right(nums, target) - 1;
        return [left, right]
