class Solution:

    def isValid(self, grid, visit, nrow, ncol):

        n = len(grid)
        m = len(grid[0])

        return nrow < n and ncol < m and nrow >= 0 and ncol >= 0 and grid[nrow][ncol] and visit[nrow][ncol]


    def BFS(self, grid, visit, r, c):

        q = deque()
        q.append([r, c])
        visit[r][c] = False

        dr = [-1, 0, 1, 0]
        dc = [0, -1, 0, 1]

        while q:
            row = q[0][0]
            col = q[0][1]
            q.popleft()

            for i in range(4):
                nrow = row + dr[i]
                ncol = col + dc[i]

                if(self.isValid(grid, visit, nrow, ncol)):
                    q.append([nrow, ncol])
                    visit[nrow][ncol] = False

    def numEnclaves(self, grid: list[list[int]]) -> int:

        n = len(grid)
        m = len(grid[0])

        visit = [[True]*m for _ in range(n)]

        for i in range(n):
            if(grid[i][0]):
                self.BFS(grid, visit, i, 0)

            if(grid[i][m-1]):
                self.BFS(grid, visit, i, m-1)
        

        for j in range(m):
            if(grid[0][j]):
                self.BFS(grid, visit, 0, j)

            if(grid[n-1][j]):
                self.BFS(grid, visit, n-1, j)

        
        count = 0
        
        for i in range(n):
            for j in range(m):
                if(grid[i][j] == 1 and visit[i][j]):
                    count += 1
        
        return count
