class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int ans = nums.size();

        int mid = start + (end - start)/2;

        while(start <= end){

            if(nums[mid] >= target){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
            
            mid = start + (end - start)/2;
        }
        return ans;
    }
};