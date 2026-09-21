class Solution {

    int solve(vector<int>& prices, int index, int buy, int fee,
              vector<vector<int>>& dp) {

        if (index == prices.size()) {
            return 0;
        }

        if (dp[index][buy] != -1) {
            return dp[index][buy];
        }

        if (buy) {

            int take =
                -prices[index] +
                solve(prices, index + 1, 0, fee, dp);

            int nottake =
                solve(prices, index + 1, 1, fee, dp);

            return dp[index][buy] =
                max(take, nottake);
        }

        else {

            int sell =
                prices[index] - fee +
                solve(prices, index + 1, 1, fee, dp);

            int hold =
                solve(prices, index + 1, 0, fee, dp);

            return dp[index][buy] =
                max(sell, hold);
        }
    }

public:

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        vector<vector<int>> dp(
            n,
            vector<int>(2, -1)
        );

        return solve(prices, 0, 1, fee, dp);
    }
};