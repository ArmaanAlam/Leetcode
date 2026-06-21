class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_index = 0;
        for(int i = 0; i < n; i++){
            if(i > max_index) return false;
            max_index = max(max_index, i + nums[i]);
            if(max_index >= n) break;
        }
        return true;
    }
};