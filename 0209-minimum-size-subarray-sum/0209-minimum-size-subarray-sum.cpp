class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int minLen = INT_MAX;
        int right = 0;
        int left = 0;
        int sum = 0;

        while(right < nums.size()){
            sum += nums[right];

            while(sum >= target){
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }

        if(minLen == INT_MAX){
            return 0;
        }

        return minLen;
    }
};