class Solution {

    void fun(vector<int>& nums, vector<vector<int>>& res, vector<int>& subset, int n, int i){

        if(i == n){
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        fun(nums, res, subset, n, i+1);
        subset.pop_back();

        fun(nums, res, subset, n, i+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        int n = nums.size();

        fun(nums, res, subset, n, 0);
        
        return res;
    }
};