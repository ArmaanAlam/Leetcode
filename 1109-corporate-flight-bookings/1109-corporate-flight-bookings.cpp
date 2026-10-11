class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        vector<int> dp(n+1);

        for(auto it : bookings){
            int first = it[0];
            int last = it[1];
            int seats = it[2];

            dp[first-1] += seats;
            dp[last] -= seats;
        }

        int prefix = 0;

        for(int i = 0; i < n; i++){
            prefix += dp[i];
            dp[i] = prefix;
        }

        return vector<int>(dp.begin(), dp.begin() + n);
    }
};