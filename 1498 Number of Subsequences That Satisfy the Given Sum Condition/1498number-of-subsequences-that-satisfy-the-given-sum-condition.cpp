class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {

        const long long MOD = 1000000007;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<long long> power(n);
        power[0] = 1;

        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        int left = 0;
        int right = n - 1;

        long long cnt = 0;

        while (left <= right) {

            if (nums[left] + nums[right] <= target) {

                cnt = (cnt + power[right - left]) % MOD;

                left++;
            }
            else {
                right--;
            }
        }

        return cnt;
    }
};