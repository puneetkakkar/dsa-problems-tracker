# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def heightOfTree(self, root):
        if root == None:
            return 0

        left_count = self.heightOfTree(root.left)
        right_count = self.heightOfTree(root.right)

        if left_count < 0 or right_count < 0 or abs(right_count - left_count) > 1:
            return -1

        return max(left_count, right_count) + 1

    def isBalanced(self, root: Optional[TreeNode]) -> bool:

        result = self.heightOfTree(root)

        return True if result >= 0 else False
