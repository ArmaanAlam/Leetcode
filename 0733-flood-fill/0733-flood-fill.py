class Solution:

    def isValid(self, image, visit, oldcolor, row, col):
        n = len(image)
        m = len(image[0])

        return row < n and col < m and row >= 0 and col >= 0 and image[row][col] == oldcolor and not visit[row][col]

    
    

    def DFS(self, image, visit, color, oldcolor, row, col):

        visit[row][col] = True
        image[row][col] = color

        dr = [-1, 0, 1, 0]
        dc = [0, -1, 0, 1]

        for i in range(4):
            nrow = row + dr[i]
            ncol = col + dc[i]

            if(self.isValid(image, visit, oldcolor, nrow, ncol)):
                self.DFS(image, visit, color, oldcolor, nrow, ncol)

        


    def floodFill(self, image: list[list[int]], sr: int, sc: int, color: int) -> list[list[int]]:

        oldcolor = image[sr][sc]

        if(oldcolor == color):
            return image

        n = len(image)
        m = len(image[0])

        visit = [[False]*m for _ in range(n)]

        self.DFS(image, visit, color, oldcolor, sr, sc)

        return image



        
        