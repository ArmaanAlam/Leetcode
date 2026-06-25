class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefix(n + 1);

        for (int i = 0; i < n; i++) {
            if (nums[i] == target)
                prefix[i + 1] = prefix[i] + 1;
            else
                prefix[i + 1] = prefix[i];
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int countprefix = prefix[j+1] - prefix[i];
                int len = j - i + 1;
                if (countprefix > (len / 2)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};