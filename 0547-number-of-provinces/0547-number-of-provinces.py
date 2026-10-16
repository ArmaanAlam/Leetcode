class Solution:

    def BFS(self, adj, visit, node):

        q = deque()
        q.append(node)
        visit[node] = 1

        while q:
            node = q[0]
            q.popleft()

            for adjnode in adj[node]:
                if visit[adjnode] == 0:
                    q.append(adjnode)
                    visit[adjnode] = 1
        

    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        
        V = len(isConnected)
        count = 0
        visit = [0] * V

        adj = [[] for _ in range(V)]
        for i in range(V):
            for j in range(V):
                if(i != j and isConnected[i][j] == 1):
                    adj[i].append(j)
                    adj[j].append(i)
        


        for i in range(V):
            if(visit[i] == 0):
                count += 1
                self.BFS(adj, visit, i)
        
        return count