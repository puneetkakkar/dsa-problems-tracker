import math
from collections import Counter

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums_counter = Counter(nums)
        majority = math.floor(len(nums) / 2)

        for i in nums_counter:
            if nums_counter[i] > majority:
                return i