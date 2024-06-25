from collections import deque


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:

        V = numCourses
        adj = [[] for _ in range(V)]

        # Create an adjacency list
        for prereq in prerequisites:
            u = prereq[1]
            v = prereq[0]
            adj[u].append(v)

        inDeg = [0] * V
        q = deque()
        visited = 0

        # Keep a count of in-degree for all vertices
        for u in range(V):
            for v in adj[u]:
                inDeg[v] += 1

        # Enqueue vertices whose in-degree is 0
        for u in range(V):
            if (inDeg[u] == 0):
                q.append(u)

        while (q):
            u = q.popleft()
            visited += 1

            for v in adj[u]:
                inDeg[v] -= 1

                if inDeg[v] == 0:
                    q.append(v)

        return visited == V
