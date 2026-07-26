class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        int len = 0;
        int sum = 0;

        for(int i = 0; i < n; i++){

            if(nums[i] == 1){
                sum++;
            }
            else{
                sum--;
            }
            if(sum == 0){
                len = max(len, i+1);
            }

            if(mp.find(sum) != mp.end()){
                len = max(len, i - mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }

        return len;
    }
};