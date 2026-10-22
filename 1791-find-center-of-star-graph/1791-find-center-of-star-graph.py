class Solution:
    def findCenter(self, edges: list[list[int]]) -> int:
        
        a, b = edges[0]
        c, d = edges[1]

        if a == c or a == d:
            return a

        return b