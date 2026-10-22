class Solution:
    def findMinHeightTrees(self, n: int, edges: list[list[int]]) -> list[int]:

        if n == 1:
            return [0]
        
        adj = [[] for _ in range(n)]
        degree = [0]*n

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
            degree[u] += 1
            degree[v] += 1
        
        q = deque()
        for i in range(n):
            if(degree[i] == 1):
                q.append(i)

        remainnode = n

        while(remainnode > 2):
            size = len(q)
            remainnode -= size

            for i in range(size):
                node = q[0]
                q.popleft()

                for adjnode in adj[node]:
                    degree[adjnode] -= 1
                    if(degree[adjnode] == 1):
                        q.append(adjnode)
         

        return list(q)


