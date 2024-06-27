import sys


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [sys.maxsize for _ in range(amount + 1)]
        dp[0] = 0

        for c in coins:
            for amt in range(1, amount + 1):
                if (amt >= c):
                    dp[amt] = min(1 + dp[amt - c], dp[amt])

        return dp[-1] if dp[-1] != sys.maxsize else -1
