class Solution:

    def DFS(self, grid1, grid2, visit, row, col):

        n = len(grid1)
        m = len(grid1[0])

        visit[row][col] = True
        dr = [-1, 0, 1, 0]
        dc = [0, -1, 0, 1]

        valid = (grid1[row][col] == 1)

        for i in range(4):
            nrow = row + dr[i]
            ncol = col + dc[i]

            if nrow >=n or ncol >= m or ncol < 0 or nrow < 0 or visit[nrow][ncol]:
                continue

            if grid2[nrow][ncol] and not visit[nrow][ncol]:
                if not self.DFS(grid1, grid2, visit, nrow, ncol):
                    valid = False
        
        return valid




    def countSubIslands(self, grid1: list[list[int]], grid2: list[list[int]]) -> int:
        
        n = len(grid1)
        m = len(grid1[0])

        visit = [[False] * m for _ in range(n)]

        count = 0

        for i in range(n):
            for j in range(m):
                if grid1[i][j] and grid2[i][j] and not visit[i][j]:
                    if self.DFS(grid1, grid2, visit, i, j):
                        count += 1
        

        return count