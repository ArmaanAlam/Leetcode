
from collections import deque

class Solution:

    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:

        adj = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses

        for u, v in prerequisites:
            adj[v].append(u)
            indegree[u] += 1

        q = deque()

        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)

        ans = []

        while q:
            node = q.popleft()
            ans.append(node)

            for adjnode in adj[node]:
                indegree[adjnode] -= 1

                if indegree[adjnode] == 0:
                    q.append(adjnode)

        return len(ans) == numCourses
