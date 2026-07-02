class Solution {

public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n+1, -1);
        
        int prev1 = nums[0];
        int prev2 = 0;

        for(int i = 1; i < n; i++){
            int include = nums[i];
            if(i > 1){
                include += prev2;
            }

            int exclude = 0 + prev1;

            int curr = max(include, exclude);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};