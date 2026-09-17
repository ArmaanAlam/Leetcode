class Solution {

    bool solve(string s, string t, int i, int j, vector<vector<int>>& dp) {

        int n = s.size();
        int m = t.size();

        if (i >= n) {
            return true;
        }


        if (j >= m) {
            return false;
        }

        if(dp[i][j] != -1) return dp[i][j];
        if (s[i] == t[j]) {
            return dp[i][j] = solve(s, t, i + 1, j + 1, dp);
        }

        return dp[i][j] = solve(s, t, i, j + 1, dp);
    }

public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(s, t, 0, 0, dp);
    }
};