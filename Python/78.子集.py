from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        l = len(nums)
        maxn = pow(2, l)
        ans: List[List[int]] = [[] for i in range(maxn)]
        for i in range(maxn):
            for j in range(l):
                if ((i >> j) & 1) == 1:
                    ans[i].append(nums[j])
        return ans
