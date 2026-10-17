class Solution:

    def isValid(self, n, m, row, col, grid, visit)-> bool:
        return row < n and col < m and row >= 0 and col >= 0 and grid[row][col] == '1' and visit[row][col] == 0

    def DFS(self, grid, visit, r, c):

        n = len(grid)
        m = len(grid[0])
        
        visit[r][c] = 1

        dr = [-1, 0, 1, 0]
        dc = [0, -1, 0, 1]

        for i in range(4):
            row = r + dr[i]
            col = c + dc[i]

            if(self.isValid(n, m, row, col, grid, visit)):
                self.DFS(grid, visit, row, col)
        


            
        
    def numIslands(self, grid: List[List[str]]) -> int:
        
        n = len(grid)
        m = len(grid[0])
        count = 0
        visit = [[0] * m for _ in range(n)]

        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1' and visit[i][j] == 0:
                    count += 1
                    self.DFS(grid, visit, i, j)
        
        return count