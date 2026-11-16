class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        
        prefix = 0
        count = 0
        mp = {0 : 1}

        for num in nums:
            prefix += num
            remain = prefix - k
            count += mp.get(remain, 0)
            mp[prefix] = mp.get(prefix, 0) + 1
        
        return count