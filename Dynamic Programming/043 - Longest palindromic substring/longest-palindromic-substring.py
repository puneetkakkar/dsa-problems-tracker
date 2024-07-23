class Solution:
    def longestPalindrome(self, s: str) -> str:

        dp = [[False for _ in range(len(s))] for _ in range(len(s))]
        max_length = 1
        starts_at = 0

        for i in range(len(s)):
            for j in range(len(s)):
                if i == j:
                    dp[i][j] = True

        for i in range(len(s) - 1):
            if s[i] == s[i + 1]:
                dp[i][i + 1] = True
                starts_at = i
                max_length = 2

        for l in range(3, len(s) + 1):
            for i in range(len(s) - l + 1):
                j = i + l - 1
                if s[i] == s[j] and dp[i + 1][j - 1]:
                    dp[i][j] = True
                    if l > max_length:
                        starts_at = i
                        max_length = l

        return s[starts_at : starts_at + max_length]
