
class Solution:

    def isValid(self, board, visit, nrow, ncol):
        n = len(board)
        m = len(board[0])

        return (0 <= nrow < n and
                0 <= ncol < m and
                not visit[nrow][ncol] and
                board[nrow][ncol] == 'O')

    def DFS(self, board, visit, row, col):
        visit[row][col] = True

        dr = [-1, 0, 1, 0]
        dc = [0, -1, 0, 1]

        for i in range(4):
            nrow = row + dr[i]
            ncol = col + dc[i]

            if self.isValid(board, visit, nrow, ncol):
                self.DFS(board, visit, nrow, ncol)

    def solve(self, board: list[list[str]]) -> None:
        if not board or not board[0]:
            return

        n = len(board)
        m = len(board[0])

        visit = [[False] * m for _ in range(n)]

        
        for i in range(n):
            if board[i][0] == 'O' and not visit[i][0]:
                self.DFS(board, visit, i, 0)

            if board[i][m - 1] == 'O' and not visit[i][m - 1]:
                self.DFS(board, visit, i, m - 1)

   
        for j in range(m):
            if board[0][j] == 'O' and not visit[0][j]:
                self.DFS(board, visit, 0, j)

            if board[n - 1][j] == 'O' and not visit[n - 1][j]:
                self.DFS(board, visit, n - 1, j)

      
        for i in range(n):
            for j in range(m):
                if board[i][j] == 'O' and not visit[i][j]:
                    board[i][j] = 'X'
