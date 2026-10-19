class Solution:
    def updateMatrix(self, mat: list[list[int]]) -> list[list[int]]:
        
        n = len(mat)
        m = len(mat[0])

        visit = [[True]*m for _ in range(n)]
        dist = [[0]*m for _ in range(n)]

        q = deque()

        for i in range(n):
            for j in range(m):
                if(mat[i][j] == 0):
                    q.append([i, j, 0])
                    dist[i][j] = 0
                    visit[i][j] = False
        
        dr = [-1, 0, 1, 0]
        dc = [0, -1, 0, 1]

        while q:
            row = q[0][0]
            col = q[0][1]
            d = q[0][2]
            q.popleft()

            for i in range(4):
                nrow = row + dr[i]
                ncol = col + dc[i]

                if(nrow < n and ncol < m and nrow >= 0 and ncol >= 0 and visit[nrow][ncol]):
                    q.append([nrow, ncol, d + 1])
                    dist[nrow][ncol] = d + 1
                    visit[nrow][ncol] = False

        

        return dist
