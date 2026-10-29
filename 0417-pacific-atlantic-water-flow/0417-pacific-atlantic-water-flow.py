class Solution:

    def DFS(self, heights, visit, row, col):

        n = len(heights)
        m = len(heights[0])

        if visit[row][col]:
            return
        visit[row][col] = True

        dr = [-1, 0, 1, 0]
        dc = [0, -1, 0, 1]

        for i in range(4):
            nrow = row + dr[i]
            ncol = col + dc[i]

            if nrow >= n or ncol >= m or ncol < 0 or nrow < 0:
                continue
            
            if heights[nrow][ncol] >= heights[row][col]:
                self.DFS(heights, visit, nrow, ncol)



    def pacificAtlantic(self, heights: list[list[int]]) -> list[list[int]]:

        n = len(heights)
        m = len(heights[0])

        pacific = [[False]*m for _ in range(n)]
        atlantic = [[False]*m for _ in range(n)]

        for i in range(n):
            self.DFS(heights, pacific, i, 0)
            self.DFS(heights, atlantic, i, m-1)

        for j in range(m):
            self.DFS(heights, pacific, 0, j)
            self.DFS(heights, atlantic, n-1, j)

        ans = []

        for i in range(n):
            for j in range(m):
                if pacific[i][j] and atlantic[i][j]:
                    ans.append([i, j])
        
        return ans
        