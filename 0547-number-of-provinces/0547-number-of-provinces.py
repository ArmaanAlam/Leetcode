class Solution:

    def DFS(self, adj, visit, node):

        visit[node] = 1

        for adjnode in adj[node]:
            if(visit[adjnode] == 0):
                self.DFS(adj, visit, adjnode)
         


    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        
        V = len(isConnected)
        visit = [0 for _ in range(V)]
        adj = [[] for _ in range(V)]

        for i in range(V):
            for j in range(V):
                if( i != j and isConnected[i][j] == 1):
                    adj[i].append(j)
                    adj[j].append(i)
        
        count = 0

        for i in range(V):
            if(visit[i] == 0):
                count += 1
                self.DFS(adj, visit, i)
            
        return count