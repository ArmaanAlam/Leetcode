class Solution {

    int solution(vector<int>& prices, int index, int buy, int cap,
                 vector<vector<vector<int>>>& dp) {

        if (index >= prices.size()) {
            return 0;
        }

        if (cap == 0) {
            return 0;
        }

        if (dp[index][buy][cap] != -1) {
            return dp[index][buy][cap];
        }

        // Don't own stock
        if (buy) {

            // Buy
            int take =
                -prices[index] +
                solution(prices, index + 1, 0, cap, dp);

            // Don't buy
            int nottake =
                solution(prices, index + 1, 1, cap, dp);

            return dp[index][buy][cap] =
                max(take, nottake);
        }

        // Own stock
        else {

            // Sell
            int sell =
                prices[index] +
                solution(prices, index + 1, 1, cap - 1, dp);

            // Hold
            int hold =
                solution(prices, index + 1, 0, cap, dp);

            return dp[index][buy][cap] =
                max(sell, hold);
        }
    }

public:

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(2, vector<int>(k + 1, -1))
        );

        return solution(prices, 0, 1, k, dp);
    }
};