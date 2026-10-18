class Solution:

    def isValid(self, grid, visit, nrow, ncol):

        n = len(grid)
        m = len(grid[0])

        return nrow < n and ncol < m and nrow >= 0 and ncol >= 0 and not visit[nrow][ncol] and grid[nrow][ncol] == 'O'


    def BFS(self, grid, visit, r, c):

        q = deque()
        q.append([r, c])
        visit[r][c] = True

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
                    visit[nrow][ncol] = True
    

    def solve(self, board: list[list[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        n = len(board)
        m = len(board[0])

        visit = [[False]*m for _ in range(n)]


        for i in range(n):
            if(board[i][0] == 'O'):
                self.BFS(board, visit, i, 0)

            if(board[i][m-1] == 'O'):
                self.BFS(board, visit, i, m-1)

        for j in range(m):
            if(board[0][j] == 'O'):
                self.BFS(board, visit, 0, j)

            if(board[n-1][j] == 'O'):
                self.BFS(board, visit, n-1, j)

        
        for i in range(n):
            for j in range(m):
                if board[i][j] == 'O' and not visit[i][j]:
                    board[i][j] = 'X'
        

