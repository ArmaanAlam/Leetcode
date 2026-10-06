class Solution {

int solve(vector<int>& nums, int index, int prev, int &n, vector<vector<int>> &dp){

    if(index >= n){
        return 0;
    }

    if(dp[index][prev + 1] != 0) return dp[index][prev + 1];

    int len = solve(nums, index + 1, prev, n, dp);

    if(prev == -1 || nums[index] > nums[prev]){
        len = max(len, 1 + solve(nums, index + 1, index, n, dp));
    }

    return dp[index][prev + 1] = len;
}

public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        int ans = solve(nums, 0, -1, n, dp);
        return ans;
    }
};