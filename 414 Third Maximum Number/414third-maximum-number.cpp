class Solution {

    static bool comp(int &a, int &b){
        return a > b;
    }

public:
    int thirdMax(vector<int>& nums) {

        sort(nums.begin(), nums.end(), comp);
        int n = nums.size();
        int k = 1;
        for(int i = 1; i < n; i++){
            if(nums[i-1] == nums[i]){
                continue;
            }
            k++;

            if(k == 3){
                return nums[i];
            }
        }

        return nums[0];
    }
};