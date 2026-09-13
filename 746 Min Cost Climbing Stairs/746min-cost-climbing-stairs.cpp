class Solution {

    int solve(vector<int>& cost, int step, vector<int>& dp) {

        if (step == 0 || step == 1) {
            return 0;
        }

        if(dp[step] != -1) return dp[step];

        return dp[step] = min(cost[step - 1] + solve(cost, step - 1, dp),cost[step - 2] + solve(cost, step - 2, dp));
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        vector<int> dp(n+1, -1);

        return solve(cost, n, dp);
    }
};