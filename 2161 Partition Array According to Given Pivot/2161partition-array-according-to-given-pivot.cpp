class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
                vector<int> ans;

        // Elements smaller than pivot
        for (int x : nums) {
            if (x < pivot)
                ans.push_back(x);
        }

        // Elements equal to pivot
        for (int x : nums) {
            if (x == pivot)
                ans.push_back(x);
        }

        // Elements greater than pivot
        for (int x : nums) {
            if (x > pivot)
                ans.push_back(x);
        }

        return ans;
    }
    
};