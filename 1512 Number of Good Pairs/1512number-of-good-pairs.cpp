class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        int cnt = 0;
        for(auto it : mp){
            cnt += ((it.second - 1)*(it.second) / 2);
        }

        return cnt;
    }
};