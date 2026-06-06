class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        vector<int> ans;
        left[0] = 0;
        right[n-1] = 0;

        for(int i = 1; i < n; i++){
            int sum = 0;
            int j = i - 1;
            while(j >= 0){
                sum += nums[j];
                j--;
            }
            left[i] = sum;
        }

        for(int i = n-2; i >= 0; i--){
            int sum = 0;
            int j = i + 1;
            while(j < n){
                sum += nums[j];
                j++;
            }
            right[i] = sum;
        }

        for(int i = 0; i < n; i++){
            int diff = abs(left[i] - right[i]);
            ans.push_back(diff);
        }

        return ans;
    }
};