class Solution {

    void permutation(vector<int> &nums, int index, vector<vector<int>> &ans){

        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }

        unordered_map<int, bool> visited;
        for(int i = index; i < nums.size(); i++){
            
            if(visited.find(nums[i]) != visited.end()){
                continue;
            }
            visited[nums[i]] = true;
            
            swap(nums[index], nums[i]);
            permutation(nums, index + 1, ans);
            swap(nums[index], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;
        permutation(nums, 0, ans);
        return ans;
    }
};