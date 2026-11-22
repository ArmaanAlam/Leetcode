class Solution:
    def checkString(self, s: str) -> bool:

        if(len(s) == 1):
            return True

        last = -1
        first = len(s)-1

        for i in range(len(s)):

            if s[i] == 'a':
                last = max(last, i)
            else:
                first = min(first, i)
        
        return last <= first