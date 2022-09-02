from typing import Optional

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: Optional[TreeNode], p: Optional[TreeNode], q: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return None
        if root is p or root is q:
            return root
        left: Optional[TreeNode] = self.lowestCommonAncestor(root.left, p, q)
        right: Optional[TreeNode] = self.lowestCommonAncestor(root.right, p, q)
        if left is None:
            return right
        if right is None:
            return left
        if left is not None and right is not None:
            return root
        return None
