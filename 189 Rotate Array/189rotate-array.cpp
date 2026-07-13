class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> ans(n);

        k = k % n;
        for(int i = 0; i < n; i++){
            int index = (i + k) % n;
            ans[index] = nums[i];
        }

        nums = ans;
    }
};