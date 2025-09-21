class Solution {

    void SubsetSum(vector<int>& nums, int i , int ans, int& total){

        if(i >= nums.size()){
            total += ans;
            return;
        }

        //Include:
        SubsetSum(nums, i + 1, ans^nums[i], total);
        //Exclude:
        SubsetSum(nums, i + 1, ans, total);

        return;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        
        int total = 0;
        int ans = 0;

        SubsetSum(nums, 0, ans, total);

        return total;
    }
};