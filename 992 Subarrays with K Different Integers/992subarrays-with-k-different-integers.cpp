class Solution {

    int subarray(vector<int>& nums, int k){

        if(k < 0) return 0;
        int n = nums.size();
        int left = 0;
        int right = 0;
        int cnt = 0;
        unordered_map<int, int>hash;

        while(right < n){
            hash[nums[right]]++;

            while(hash.size() > k){
                hash[nums[left]]--;
                if(hash[nums[left]] == 0){
                    hash.erase(nums[left]);
                }
                left++;
            }

            cnt += right - left + 1;
            right++;
        } 
        return cnt;
    }


public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int first = subarray(nums, k);
        int second = subarray(nums, k-1);

        return first - second;
    }
};