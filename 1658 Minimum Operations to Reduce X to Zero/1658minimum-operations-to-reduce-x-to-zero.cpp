class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();
        int total = 0;
        for (int num : nums)
            total += num;

        int k = total - x;

        if (k < 0)
            return -1;
        if (k == 0)
            return n;

        int i = 0;
        int sum = 0;
        int ans = -1;
        for (int j = 0; j < n; j++) {
            sum += nums[j];

            while (sum > k) {
                sum -= nums[i];
                i++;
            }

            if (sum == k) {
                ans = max(ans, j - i + 1);
            }
        }

        return ans == -1 ? -1 : n - ans;
    }
};