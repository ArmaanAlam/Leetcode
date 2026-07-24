class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int diff = INT_MAX;

        for(int i = 0; i < n; i++){
            int left = i+1;
            int right = n-1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];

                if(sum > target){
                    right--;
                }
                else if(sum < target){
                    left++;
                }

                int oldDiff = diff;
                diff = abs(sum - target);

                if(diff <= oldDiff){
                    ans = sum;
                }
                else{
                    diff = oldDiff;
                }

                if(diff == 0) return ans;
            }
        }
        return ans;
    }
};