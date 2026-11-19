class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int el1 = nums[n-1] - nums[2];
        int el2 = nums[n-2] - nums[1];
        int el3 = nums[n-3] - nums[0];

        return min({el1, el2, el3});
    }
};