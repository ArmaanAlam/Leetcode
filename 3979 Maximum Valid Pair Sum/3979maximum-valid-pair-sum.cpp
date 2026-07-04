class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {

        int ans = INT_MIN;
        int max_ans = INT_MIN;

        for(int j = k; j < nums.size(); j++){
            max_ans = max(max_ans, nums[j-k]);
            ans = max(ans, max_ans + nums[j]);
        }
        
        

        return ans;
    }
};