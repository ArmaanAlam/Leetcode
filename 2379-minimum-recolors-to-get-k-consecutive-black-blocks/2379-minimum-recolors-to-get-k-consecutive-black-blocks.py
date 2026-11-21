class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:

        left = 0
        right = 0
        white = 0
        mincolor = float("inf")

        while right < len(blocks):

            if blocks[right] == "W":
                white += 1
            
            if right - left + 1 > k:
                if blocks[left] == "W":
                    white -= 1
                left += 1
            
            if right - left + 1 == k:
                mincolor = min(mincolor, white)
            
            right += 1

        
        return mincolor
        