class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        int max_len = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] != 1){
                len = 0;
            }
            else{
                len++;
            }
            max_len = max(len, max_len);
        }
        return max_len;
    }
};