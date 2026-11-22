class Solution:
    def minimumDifference(self, nums: list[int], k: int) -> int:

        nums.sort()
        left = 0
        right = k-1
        res = float('inf')

        while right < len(nums):
            res = min(res, nums[right] - nums[left])
            right += 1
            left += 1
        return res
        