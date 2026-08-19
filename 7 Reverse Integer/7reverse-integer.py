class Solution:
    def reverse(self, x: int) -> int:
        
        sign = -1 if x < 0 else 1
        
        n = str(abs(x))
        y = n[::-1]
        
        ans = sign * int(y)
        
        if ans > 2**31 - 1 or ans < -2**31:
            return 0
        
        return ans