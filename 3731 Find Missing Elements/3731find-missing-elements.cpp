class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int start = nums[0];
        int end = nums[n-1];

        for(int i = start; i <= end; i++){
            if(find(nums.begin(), nums.end(), i) == nums.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};