class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        no_of_islands = 0
        visited = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]

        def traverseLand(start):
            sr, sc = start[0], start[1]

            visited[sr][sc] = "1"

            if sc > 0 and grid[sr][sc - 1] == "1" and visited[sr][sc - 1] != "1":
                new_start = (sr, sc - 1)
                traverseLand(new_start)

            if sr > 0 and grid[sr - 1][sc] == "1" and visited[sr - 1][sc] != "1":
                new_start = (sr - 1, sc)
                traverseLand(new_start)

            if (
                sc < len(grid[0]) - 1
                and grid[sr][sc + 1] == "1"
                and visited[sr][sc + 1] != "1"
            ):
                new_start = (sr, sc + 1)
                traverseLand(new_start)

            if (
                sr < len(grid) - 1
                and grid[sr + 1][sc] == "1"
                and visited[sr + 1][sc] != "1"
            ):
                new_start = (sr + 1, sc)
                traverseLand(new_start)

            return start

        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if (grid[r][c] == "0") or (grid[r][c] == "1" and visited[r][c] == "1"):
                    continue

                if grid[r][c] == "1":
                    start = (r, c)
                    # end = (-1, -1)

                    end = traverseLand(start)

                    if start[0] == end[0] and start[1] == end[1]:
                        no_of_islands += 1

        # print(visited)

        return no_of_islands
