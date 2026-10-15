class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            mp.clear();

            for (int j = i; j < n; j++) {
                mp[nums[j]]++;
                int distinct = mp.size();
                ans += distinct * distinct;
            }
        }

        return ans;
    }
};