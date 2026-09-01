class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int currsum = 0;
        int cnt = 0;
        unordered_map<int, int>mp;
        mp[0] = 1;

        for(int i = 0; i < n; i++){
            currsum += nums[i];
            int rem = (currsum % k + k) % k;
            cnt += mp[rem];
            mp[rem]++;
        }

        return cnt;
    }
};