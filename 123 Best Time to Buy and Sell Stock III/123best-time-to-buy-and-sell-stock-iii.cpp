class Solution {

    int solution(vector<int>& prices,int index, int buy, int cap,
    vector<vector<vector<int>>>& dp){
        
        if(index >= prices.size()){
            return 0;
        }

        if(cap == 0){
            return 0;
        }

        if(dp[index][buy][cap] != -1) return dp[index][buy][cap];

        if(buy){
            int take = -prices[index] + solution(prices, index+1, 0, cap, dp);
            int nottake = solution(prices, index+1, 1, cap, dp);
            return dp[index][buy][cap] = max(take, nottake);
        }
        else{
            int take = prices[index] + solution(prices, index+1, 1, cap-1, dp);
            int nottake = solution(prices, index+1, 0, cap, dp);
            return dp[index][buy][cap] = max(take, nottake);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solution(prices, 0, 1, 2, dp);
    }
};