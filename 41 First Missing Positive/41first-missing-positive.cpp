class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int target = 1;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            if(nums[i] < target) continue;
            if(nums[i] == target){
                target++;
            }
            else{
                break;
            }
        }
        return target;
    }
};