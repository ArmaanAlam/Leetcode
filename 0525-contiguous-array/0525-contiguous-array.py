class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        
        count = 0
        length = 0

        mp = {}

        for i in range(len(nums)):

            if nums[i] == 1:
                count += 1
            else:
                count -= 1
            
            if count == 0:
                length = max(length, i+1)

            if count in mp:
                length = max(length, i - mp[count])
            else:
                mp[count] = i
        

        return length