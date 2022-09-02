from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if self.maxDepth(root) == -1:
            return False
        return True

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        left: int = self.maxDepth(root.left)
        right: int = self.maxDepth(root.right)
        if left == -1 or right == -1 or left - right > 1 or right - left > 1:
            return -1
        return 1 + max(left, right)
