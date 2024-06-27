from collections import deque


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = []
        suffix = []
        ans = []

        # Calculating prefix product
        for idx, num in enumerate(nums):
            if idx == 0:
                prefix.append(1)
            else:
                product = prefix[idx - 1] * nums[idx - 1]
                prefix.append(product)

        # Calculating suffix product
        for idx, num in reversed(list(enumerate(nums))):
            if idx == len(nums) - 1:
                suffix.append(1)
            else:
                product = suffix[len(nums) - (idx + 2)] * nums[idx + 1]
                suffix.append(product)

        for i in range(len(nums)):
            product = prefix[i] * suffix[len(nums) - i - 1]
            ans.append(product)

        return ans
