class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int m = s.size();

        unordered_set<string> st;

        for (string str : wordDict) {
            st.insert(str);
        }

        vector<bool> dp(m + 1, false);

        dp[m] = true;

        for (int i = m - 1; i >= 0; i--) {

            for (int j = i; j < m; j++) {

                string str = s.substr(i, j - i + 1);

                if (st.count(str) && dp[j + 1]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};