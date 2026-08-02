class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++){
            dp[i][i] = nums[i];
        }


        for(int len = 2; len <= n; len++){
            int i = 0;
            int j = len - 1;

            while(j < n){
                dp[i][j] = max(
                    nums[i] - dp[i+1][j],
                    nums[j] - dp[i][j-1]
                );
                i++;
                j++;
            }
        }

        return dp[0][n - 1] >= 0;
    }
};