from typing import List
import random

class Solution:

    def __init__(self, nums: List[int]):
        self.original = nums
        self.shuffled = self.original.copy()


    def reset(self) -> List[int]:
        self.shuffled = self.original.copy()
        return self.shuffled

    def shuffle(self) -> List[int]:
        for i in range(len(self.shuffled)):
            j = i + random.randrange(len(self.shuffled) - i)
            self.shuffled[i], self.shuffled[j] = self.shuffled[j], self.shuffled[i]
        return self.shuffled



# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
