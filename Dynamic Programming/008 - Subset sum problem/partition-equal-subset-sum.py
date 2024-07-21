class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        ans = False
        total_sum = sum(nums)
        req_sum = total_sum // 2

        if total_sum % 2 == 0:
            table = [[False for i in range(req_sum + 1)] for _ in range(len(nums) + 1)]

            for i in range(len(table)):
                table[i][0] = True

            for i in range(1, len(table[0])):
                table[0][i] = False

            for r in range(1, len(table)):
                for c in range(1, len(table[0])):
                    if c < nums[r - 1]:
                        table[r][c] = table[r - 1][c]
                    else:
                        table[r][c] = table[r - 1][c] or table[r - 1][c - nums[r - 1]]

            if table[r][c] == True:
                ans = True

        return ans
