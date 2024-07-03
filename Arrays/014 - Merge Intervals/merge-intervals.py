class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:

        m = len(intervals)
        n = len(intervals[0])

        intervals.sort(key=lambda x: x[0])

        start = intervals[0][0]
        end = intervals[0][1]

        ans = []

        for i in range(m):            
            if intervals[i][0] >= start and intervals[i][0] <= end:
                start = min(intervals[i][0], start)
                end = max(intervals[i][1], end)
            else:
                ans.append([start, end])
                start = intervals[i][0] 
                end = intervals[i][1]

        ans.append([start, end])

        return ans