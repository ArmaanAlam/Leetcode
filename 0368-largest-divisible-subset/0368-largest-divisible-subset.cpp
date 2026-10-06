
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int prev = index - 1; prev >= -1; prev--) {

                int len = dp[index + 1][prev + 1];

                if (prev == -1 || nums[index] % nums[prev] == 0) {
                    len = max(len, 1 + dp[index + 1][index + 1]);
                }

                dp[index][prev + 1] = len;
            }
        }

        vector<int> ans;
        int prev = -1;

        for (int index = 0; index < n; index++) {

            int skip = dp[index + 1][prev + 1];

            if (prev == -1 || nums[index] % nums[prev] == 0) {
                int take = 1 + dp[index + 1][index + 1];

                if (take >= skip) {
                    ans.push_back(nums[index]);
                    prev = index;
                }
            }
        }

        return ans;
    }
};
