class Solution {

    int solve(vector<int>& coins, int index, int amount, vector<vector<int>>& dp){

        if(amount == 0){
            return 1;
        }

        if(index >= coins.size()){
            return 0;
        }

        if(dp[index][amount] != -1) return dp[index][amount];

        int take = 0;
        if(coins[index] <= amount){
            take = solve(coins, index, amount - coins[index], dp);
        }

        int nottake = solve(coins, index+1, amount, dp);

        return dp[index][amount] = take + nottake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(coins, 0, amount, dp);
    }
};