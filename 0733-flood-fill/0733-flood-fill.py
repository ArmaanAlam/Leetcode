class Solution:

    def isValid(self, image, visit, oldcolor, row, col):
        n = len(image)
        m = len(image[0])

        return row < n and col < m and row >= 0 and col >= 0 and image[row][col] == oldcolor and not visit[row][col]

    def BFS(self, image, visit, color, oldcolor, row, col):
        q = deque()
        q.append([row, col])
        image[row][col] = color
        visit[row][col] = True

        dr = [-1, 0, 1, 0]
        dc = [0, -1, 0, 1]

        while q:
            r = q[0][0]
            c = q[0][1]
            q.popleft()

            for i in range(4):
                nrow = r + dr[i]
                ncol = c + dc[i]

                if(self.isValid(image, visit, oldcolor, nrow, ncol)):
                    q.append([nrow, ncol])
                    image[nrow][ncol] = color
                    visit[nrow][ncol] = True
        


    def floodFill(self, image: list[list[int]], sr: int, sc: int, color: int) -> list[list[int]]:

        oldcolor = image[sr][sc]

        if(oldcolor == color):
            return image

        n = len(image)
        m = len(image[0])

        visit = [[False]*m for _ in range(n)]

        self.BFS(image, visit, color, oldcolor, sr, sc)

        return image



        
        