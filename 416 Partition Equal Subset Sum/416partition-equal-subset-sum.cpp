class Solution {

    bool solve(vector<int>& nums, int& n, int index, int target, vector<vector<int>>& dp){

        if(target == 0){
            return true;
        }

        if(index >= n || target < 0){
            return false;
        }

        if(dp[index][target] != -1) return dp[index][target];

        bool include = solve(nums, n, index+1, target - nums[index], dp);
        bool exclude = solve(nums, n, index+1, target, dp);

        return dp[index][target] = include || exclude;
    }

public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int totalSum = 0;
        for(int num : nums){
            totalSum += num;
        }

        if(totalSum % 2) return false;
        int target = totalSum / 2;

        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        return solve(nums, n, 0, target, dp);
    }
};