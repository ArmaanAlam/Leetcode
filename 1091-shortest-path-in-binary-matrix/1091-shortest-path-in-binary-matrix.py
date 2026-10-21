from collections import deque
class Solution:
    def shortestPathBinaryMatrix(self, grid: list[list[int]]) -> int:

        n = len(grid)
        m = len(grid[0])

        if(grid[0][0] == 1):
            return -1
        
        if(n == 1 and m == 1):
            return 1

        dist = [[float('inf')] * m for _ in range(n)]
        q = deque()
        q.append([1, 0, 0])
        dist[0][0] = 1

        dr = [-1, -1, 0, 1, 1, 1, 0, -1]
        dc = [0, 1, 1, 1, 0, -1, -1, -1]

        while q:
            r = q[0][1]
            c = q[0][2]
            d = q[0][0]
            q.popleft()

            if(r == n-1 and c == m-1):
                return d

            for i in range(8):
                row = r + dr[i]
                col = c + dc[i]

                if(row < n and col < m and row >= 0 and col >= 0 and grid[row][col] == 0):

                    
                    if(d + 1 < dist[row][col]):
                        dist[row][col] = d + 1
                        q.append([dist[row][col], row, col])


        return -1
                
