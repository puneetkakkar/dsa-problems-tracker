from collections import deque


class MatrixBFS:
    def BFS(self, matrix):
        DIR = [0, 1, 0, -1, 0]
        m = len(matrix)
        n = len(matrix[0])

        sr, sc = 0, 0

        q = deque()
        visited = [[False for _ in range(n)] for _ in range(m)]

        q.append((sr, sc))
        visited[sr][sc] = True

        while q:
            q_size = len(q)

            # This for loop makes sure that all the
            # prior elements are executed first and
            # then later added elements are executed then
            for _ in range(q_size):
                r, c = q.popleft()
                for i in range(4):
                    nr, nc = r + DIR[i], c + DIR[i + 1]

                    # check for validity
                    if (
                        nr < 0
                        or nr == m
                        or nc < 0
                        or nc == n
                        or visited[nr][nc] == True
                    ):
                        continue

                    visited[nr][nc] = True
                    q.append((nr, nc))

        return visited


# if __name__ == "__main__":

#     grid = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]

#     inst = MatrixBFS()
#     ans = inst.BFS(grid)

#     print(ans)
