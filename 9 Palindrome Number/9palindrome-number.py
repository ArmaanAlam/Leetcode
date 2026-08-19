class Solution:
    def isPalindrome(self, x: int) -> bool:
        
        if(x < 0):
            return False
        
        lis = [int(digit) for digit in str(x)]
        n = len(lis)

        i = 0
        j = n-1

        while(i < j):
            if(lis[i] != lis[j]):
                return False
            i += 1
            j -= 1
        
        return True
