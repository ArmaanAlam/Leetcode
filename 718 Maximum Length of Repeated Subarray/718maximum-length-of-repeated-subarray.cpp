class Solution {

    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& dp) {

        int n = nums1.size();
        int m = nums2.size();

        if (i >= n || j >= m) {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if (nums1[i] == nums2[j]) {
            return dp[i][j] = 1 + solve(nums1, nums2, i + 1, j + 1, dp);
        }

        return dp[i][j] = 0;
    }

public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                ans = max(ans, solve(nums1, nums2, i, j, dp));
            }
        }

        return ans;
    }
};