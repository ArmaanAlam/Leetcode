class Solution:
    def orangesRotting(self, grid: list[list[int]]) -> int:

        n = len(grid)
        m = len(grid[0])
        visit = [[True]*m for _ in range(n)]
        q = deque()

        for i in range(n):
            for j in range(m):
                if(grid[i][j] == 2):
                    q.append([i, j, 0])
                    visit[i][j] = False
                elif(grid[i][j] == 0):
                    visit[i][j] = False


        time = 0

        dr = [-1, 0, 1, 0]
        dc = [0, -1, 0, 1]

        while q:
            r = q[0][0]
            c = q[0][1]
            t = q[0][2]
            q.popleft()

            time = max(time, t)

            for i in range(4):
                row = r + dr[i]
                col = c + dc[i]

                if(row < n and col < m and row >= 0 and col >= 0 and grid[row][col] == 1 and visit[row][col]):
                    q.append([row, col, t + 1])
                    visit[row][col] = False
            
        
        for i in range(n):
            for j in range(m):
                if(grid[i][j] == 1 and visit[i][j]):
                    return -1
        

        return time