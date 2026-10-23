class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = INT_MAX;
        bool found = false;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                k &= nums[i];
                found = true;
            }
        }

        if (!found)
            return 0;

        return k;
    }
};