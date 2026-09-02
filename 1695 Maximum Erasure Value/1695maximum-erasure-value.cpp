class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = 0;
        int left = 0;
        int right = 0;
        unordered_set<int> st;
        int curr = 0;

        while(right < n){
            
            while(st.count(nums[right])){
                curr -= nums[left];
                st.erase(nums[left]);
                left++;
            }

            curr += nums[right];
            st.insert(nums[right]);
            maxSum = max(maxSum, curr);
            right++;
        }

        return maxSum;
    }
};