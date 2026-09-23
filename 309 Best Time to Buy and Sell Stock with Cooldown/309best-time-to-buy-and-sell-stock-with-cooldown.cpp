class Solution {

    int solve(vector<int>& prices, int index, int buy, vector<vector<int>>& dp){

        if(index >= prices.size()){
            return 0;
        }

        if(dp[index][buy] != -1) return dp[index][buy];

        if(buy){
            int take = -prices[index] + solve(prices, index+1, 0, dp);
            int nottake = solve(prices, index+1, 1, dp);
            return dp[index][buy] = max(take, nottake);
        }
        else{
            int take = prices[index] + solve(prices, index+2, 1, dp);
            int nottake = solve(prices, index+1, 0, dp);
            return dp[index][buy] = max(take, nottake);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, 0, 1, dp);
    }
};