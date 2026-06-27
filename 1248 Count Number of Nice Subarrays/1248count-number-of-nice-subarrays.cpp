class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> array(n, 0);
        for(int i = 0; i < n; i++) if(nums[i] % 2 != 0) array[i] = 1;

        unordered_map<int, int>hash;
        hash[0] = 1;

        int total = 0;
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += array[i];
            int remain = sum - k;

            if(hash.find(remain) != hash.end()){
                total += hash[remain];
            }
            hash[sum]++;
        }

        return total;
    }
};