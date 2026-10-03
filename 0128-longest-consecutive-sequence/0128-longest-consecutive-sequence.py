class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:

        if not nums:
            return 0

        nums.sort()

        max_len = 1
        curr_len = 1

        for i in range(1, len(nums)):

            if nums[i] == nums[i - 1]:
                continue

            if nums[i] == nums[i - 1] + 1:
                curr_len += 1
            else:
                curr_len = 1

            max_len = max(max_len, curr_len)

        return max_len