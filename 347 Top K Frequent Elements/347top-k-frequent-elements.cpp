class Solution {

    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        vector<pair<int, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), cmp);

        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(vec[i].first);
        }

        return ans;
    }
};