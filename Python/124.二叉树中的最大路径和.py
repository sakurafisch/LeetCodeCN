from typing import Optional
import sys

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self):
        self.ans: int = -sys.maxsize - 1

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.maxPath(root)
        return self.ans

    def maxPath(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        left: int = max(0, self.maxPath(root.left))
        right: int = max(0, self.maxPath(root.right))
        newPath: int = root.val + left + right
        self.ans = max(self.ans, newPath)
        return root.val + max(left, right)
