class Solution {
public:
    int solve(int index, int target,
              vector<int>& nums,
              vector<vector<int>>& dp) {

        if(index == 0) {
            if(target == 0 && nums[0] == 0)
                return 2;

            if(target == 0 || target == nums[0])
                return 1;

            return 0;
        }

        if(dp[index][target] != -1)
            return dp[index][target];

        int notTake = solve(index - 1, target, nums, dp);

        int take = 0;

        if(nums[index] <= target) {
            take = solve(
                index - 1,
                target - nums[index],
                nums,
                dp
            );
        }

        return dp[index][target] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int totalSum = 0;

        for(int x : nums)
            totalSum += x;

        // Impossible cases
        if(abs(target) > totalSum)
            return 0;

        int remaining = totalSum + target;

        if(remaining % 2 != 0)
            return 0;

        int subsetTarget = remaining / 2;

        vector<vector<int>> dp(
            n,
            vector<int>(subsetTarget + 1, -1)
        );

        return solve(n - 1, subsetTarget, nums, dp);
    }
};