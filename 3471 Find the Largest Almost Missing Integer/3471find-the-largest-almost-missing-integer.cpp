class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_map<int, int> freq;

        for (int i : nums) {
            freq[i]++;
        }

        int ans = -1;

        if (n == k) {
            for (int i : nums) {
                ans = max(ans, i);
            }
        } else if (k == 1) {
            for (int i : nums) {
                if (freq[i] == 1) {
                    ans = max(ans, i);
                }
            }
        } else {
            if (freq[nums[0]] == 1) {
                ans = max(ans, nums[0]);
            }
            if (freq[nums[n - 1]] == 1) {
                ans = max(ans, nums[n - 1]);
            }
        }

        return ans;
    }
};