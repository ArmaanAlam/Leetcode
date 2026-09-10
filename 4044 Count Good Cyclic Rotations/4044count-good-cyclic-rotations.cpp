class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        
        int n = nums.size();
        int half = n / 2;
        
        long long total = 0;
        
        for (int x : nums) {
            total += x;
        }

        long long pre = 0;
        
        for (int i = 0; i < half; i++) {
            pre += nums[i];
        }

        int cnt = 0;

        for (int start = 0; start < n; start++) {
            
            if (pre > total - pre) {
                cnt++;
            }

            pre -= nums[start];
            pre += nums[(start + half) % n];
        }

        return cnt;
    }
};