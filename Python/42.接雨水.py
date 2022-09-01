from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        ans: int = 0
        n: int = len(height)
        if height is None:
            return ans
        leftheight: List[int] = [0] * n
        rightheight: List[int] =[0] * n
        leftheight[0] = height[0]
        rightheight[n-1] = height[n-1]
        for i in range(1, n):
            leftheight[i] = max(leftheight[i-1], height[i])
        for i in range(n-2, -1, -1):
            rightheight[i] = max(rightheight[i+1], height[i])
        for i in range(0, n):
            ans += min(leftheight[i], rightheight[i]) - height[i]
        return ans
