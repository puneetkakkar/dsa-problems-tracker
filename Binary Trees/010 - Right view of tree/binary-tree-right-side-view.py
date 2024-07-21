# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ans = []

        if root is None:
            return ans

        q = deque()
        q.append([root])

        while q:
            lvl_list = q.popleft()
            new_lvl_list = []

            ans.append(lvl_list[-1].val)

            for node in lvl_list:

                if node and node.left is not None:
                    new_lvl_list.append(node.left)

                if node and node.right is not None:
                    new_lvl_list.append(node.right)

            if len(new_lvl_list) > 0:
                q.append(new_lvl_list)

        return ans
