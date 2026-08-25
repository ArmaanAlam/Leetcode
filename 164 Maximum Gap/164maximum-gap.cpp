class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;

        int diff = 0;
        sort(nums.begin(), nums.end());

        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i-1] > diff){
                diff = nums[i] - nums[i-1];
            }
        }

        return diff;
    }
};