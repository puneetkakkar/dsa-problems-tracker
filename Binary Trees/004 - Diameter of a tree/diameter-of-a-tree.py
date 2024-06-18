# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    diameter = 0

    def height(self, root):
        if root == None:
            return 0

        left_count = self.height(root.left)
        right_count = self.height(root.right)

        self.diameter = max(self.diameter, left_count + right_count)

        return max(left_count, right_count) + 1

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.height(root)
        return self.diameter
