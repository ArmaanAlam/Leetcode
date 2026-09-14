class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();

        long long sum = 0;

     
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }

        double ans = (double)sum / k;

        int left = 0;
        int right = k;

       
        while(right < n){

            sum += nums[right];   
            sum -= nums[left];    

            ans = max(ans, (double)sum / k);

            left++;
            right++;
        }

        return ans;
    }
};