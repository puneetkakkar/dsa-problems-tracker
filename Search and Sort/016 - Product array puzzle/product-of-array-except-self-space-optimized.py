from collections import deque


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ans = []

        # Calculating prefix product
        current = 1
        for idx in range(len(nums)):
            if idx == 0:
                ans.append(current)
            else:
                product = ans[idx - 1] * nums[idx - 1]
                ans.append(product)

        # Calculating suffix product
        current = 1
        for idx in range(len(nums) - 1, -1, -1):
            ans[idx] *= current
            current *= nums[idx]

        return ans
