class Solution {

private:

    int solve(vector<int>& prices, int day, int canBuy,
              vector<vector<int>>& dp) {

        // No days left
        if (day == prices.size()) {
            return 0;
        }

        // Already calculated
        if (dp[day][canBuy] != -1) {
            return dp[day][canBuy];
        }


        // We don't own a stock
        if (canBuy == 1) {

            // Buy today
            int buy =
                -prices[day] +
                solve(prices, day + 1, 0, dp);

            // Don't buy today
            int notBuy =
                solve(prices, day + 1, 1, dp);

            // Store the answer
            return dp[day][canBuy] =
                max(buy, notBuy);
        }


        // We already own a stock
        else {

            // Sell today
            int sell =
                prices[day] +
                solve(prices, day + 1, 1, dp);

            // Hold the stock
            int hold =
                solve(prices, day + 1, 0, dp);

            // Store the answer
            return dp[day][canBuy] =
                max(sell, hold);
        }
    }


public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(prices, 0, 1, dp);
    }
};