#User function Template for python3

'''
# Node Class:
class Node:
    def _init_(self,val):
        self.data = val
        self.left = None
        self.right = None
        '''
class Solution:
    #Function to find the height of a binary tree.
    def height(self, root):
        if root is None:
            return 0
            
        left_count = self.height(root.left)
        right_count = self.height(root.right)
        
        return max(left_count, right_count) + 1
