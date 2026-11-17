class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        int max_freq = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
            max_freq = max(max_freq, mp[nums[i]]);
        }

        vector<pair<int, int>> pq(mp.begin(), mp.end());

        for(int i = 0; i < pq.size(); i++){
            if(pq[i].second == max_freq){
                count += max_freq;
            }
        }

        return count;

    }
};