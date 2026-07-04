class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for(int i : nums){
            mp[i]++;
        }

        int mid = n/2;

        if(mp[nums[mid]] != 1){
            return false;
        }

        return true;
    }
};