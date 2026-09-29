class Solution:
    def largestOddNumber(self, num: str) -> str:
        
        n = len(num)
        i = n-1

        for i in range(n-1, -1, -1):
            n = int(num[i])
            if(n % 2 != 0):
                return num[0:i+1]
            else:
                continue
        
        return ""