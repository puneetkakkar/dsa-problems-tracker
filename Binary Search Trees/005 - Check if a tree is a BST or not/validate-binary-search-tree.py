# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.bst_list = []

    def checkBST(self, root: Optional[TreeNode]):
        if root == None:
            return

        left_node = self.checkBST(root.left)

        self.bst_list.append(root.val)

        right_node = self.checkBST(root.right)

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        self.checkBST(root)

        for i in range(len(self.bst_list) - 1):
            if self.bst_list[i] >= self.bst_list[i + 1]:
                return False

        return True
