class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        unordered_map<int, int>hash;
        hash[0] = 1;

        int n = nums.size();
        int total = 0;
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            int remain = sum - goal;

            if(hash.find(remain) != hash.end()){
                total += hash[remain];
            }
            hash[sum]++;
        }

        return total;
    }
};