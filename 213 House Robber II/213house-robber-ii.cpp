class Solution {

    int robbery(vector<int>& nums) {

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
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp1, temp2;

        for(int i = 0; i < n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }

        int first = robbery(temp1);
        int second = robbery(temp2);

        return max(first, second);

    }
};