class Solution:

    def DFS(self, graph, visit, pathvisit, safe, node):

        visit[node] = True
        pathvisit[node] = True

        for adjnode in graph[node]:

           
            if not visit[adjnode]:
                if self.DFS(graph, visit, pathvisit, safe, adjnode):
                    safe[node] = 0
                    return True

           
            elif pathvisit[adjnode]:
                safe[node] = 0
                return True

        pathvisit[node] = False
        safe[node] = 1
        return False

    def eventualSafeNodes(self, graph: list[list[int]]) -> list[int]:

        V = len(graph)
        visit = [False] * V
        pathvisit = [False] * V
        safe = [0] * V
        ans = []

        for i in range(V):
            if not visit[i]:
                self.DFS(graph, visit, pathvisit, safe, i)

        for i in range(V):
            if safe[i] == 1:
                ans.append(i)

        return ans