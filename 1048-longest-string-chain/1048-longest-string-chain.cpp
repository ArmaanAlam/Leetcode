class Solution {

    bool isPredecessor(string &prev, string &curr) {
        if (curr.size() != prev.size() + 1)
            return false;

        int i = 0;
        int j = 0;

        while (i < prev.size() && j < curr.size()) {

            if (prev[i] == curr[j]) {
                i++;
                j++;
            }
            else {
                j++;
            }
        }

        return i == prev.size();
    }

    int solve(vector<string>& words, int index, int prev, int n, vector<vector<int>>& dp) {

        if (index >= n)
            return 0;

        if (dp[index][prev + 1] != -1)
            return dp[index][prev + 1];

        int len = solve(words, index + 1, prev, n, dp);

        if (prev == -1 ||
            isPredecessor(words[prev], words[index])) {

            len = max(
                len,
                1 + solve(words, index + 1, index, n, dp)
            );
        }

        return dp[index][prev + 1] = len;
    }

    static bool comp(string &s1, string &s2){
        return s1.size() < s2.size();
    }

public:

    int longestStrChain(vector<string>& words) {

        int n = words.size();

        sort(words.begin(), words.end(), comp);

        vector<vector<int>> dp(n,vector<int>(n + 1, -1));

        return solve(words, 0, -1, n, dp);
    }
};