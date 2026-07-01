class Solution {

    int fun(int n, vector<int>&dp){

        if(n <= 1) return 1;

        if(dp[n] != -1) return dp[n];

        int left = fun(n-1, dp);
        int right = fun(n-2, dp);

        return dp[n] = left + right;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return fun(n, dp);
    }
};