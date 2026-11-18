class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        int left = 0;
        long long currSum = 0;
        long long maxSum = 0;

        for (int right = 0; right < nums.size(); right++) {

            currSum += nums[right];
            mp[nums[right]]++;

            while (mp[nums[right]] > 1 || right - left + 1 > k) {

                currSum -= nums[left];
                mp[nums[left]]--;

                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }

                left++;
            }

            if (right - left + 1 == k) {
                maxSum = max(maxSum, currSum);
            }
        }

        return maxSum;
    }
};